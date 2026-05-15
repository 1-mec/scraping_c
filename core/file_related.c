#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
#include <stdbool.h>

#include "../header/file_related.h"
#include "../header/utils.h"

void save_log(char * fragment,char * host,char * password,char * path,char * port,char * query,char * scheme,char * user,char * zoneid){

    int fd = open("log.txt", O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    if (flock( fd,LOCK_EX) == -1 ){
        perror("flock");
        close(fd);
        exit(1);
    }

    char * tmp = aff_host_path_scheme(host,path,scheme);

    write(fd,tmp,strlen(tmp));
    flock( fd,LOCK_UN);
    free(tmp);
    close(fd);
}

void read_file(char * file){

    int fd = open(file  , O_RDONLY );
    if (fd == -1){
        perror("open");
        exit(1) ;
    }

    char c;
    char last[12] = "";
    char res[4096] = "";
    int cpt = 0;
    bool fst = false;
    int nb_links = 0;
    int max_links = 360;

    ssize_t rd ;

    char ** lst = malloc(max_links * sizeof(char *) );
    if (lst == NULL){
        perror("malloc");
        exit(1);
    }

    while((rd = read(fd,&c,1)) >0){
        
        memmove(last , last+1 , 10);
        last[10] = c;
        last[11] = '\0';

        if (strcmp(last,"href=\"https") == 0){
            fst = true;
            cpt = 0;
            res[0] = '\0';
            continue;
        }

        if (fst){
            if (c == '"'){
                res[cpt] = '\0';
                int len = strlen(res)+strlen("lien = https\n")+1;
                char * tmp = malloc(len);
                snprintf(tmp,len,"lien = https%s\n",res);
                lst[nb_links] =strdup(tmp);
                free(tmp);

                fst = false;
                cpt = 0;
                nb_links++;
            } else if (cpt < sizeof(res)-1) res[cpt++] = c;
            
        }
        
    }

    if (rd == -1) {
        perror("read");
    }

    for( int i = 0; i < nb_links ; i++){
        //printf("-> %s\n",lst[i]);
        free(lst[i]);
    }
    free(lst);
    
    printf("il y a %d liens\n",nb_links);

    close(fd);
}
