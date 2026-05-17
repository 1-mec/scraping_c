#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <fcntl.h>
#include <unistd.h>
#include <sys/file.h>
#include <stdbool.h>

#include "../header/file_related.h"
#include "../header/utils.h"

int nb_links = 0;
int max_links = 360;

char ** lst ;
items * test;

void save_lst(items * res , char * tmp , int index){
    res[index].lst = malloc((strlen(tmp)+1));
    res[index].index = index+1;
    strcpy(res[index].lst,tmp);
}

items * init_items(){
    items * test = (items *)malloc(sizeof(items)*max_links);
    return test;
}


void free_items(items * res){
    for (int i  = 0; i < nb_links ; i++){
        free(res[i].lst);
        free(res[i].index);
    }
    free(res);
}


void save_log(char * fragment,char * host,char * password,char * path,char * port,char * query,char * scheme,char * user,char * zoneid){

    int fd = open("results/log.txt", O_WRONLY | O_CREAT | O_TRUNC , S_IRUSR | S_IWUSR);
    if (fd == -1) {
        perror("open_save");
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

    char * tmp = strdup(file);
    ssize_t len = strlen(file)+strlen("results/")+1;
    snprintf(file,len,"results/%s",tmp);
    

    test =  init_items();
    
    int fd = open(file  , O_RDONLY );
    if (fd == -1){
        perror("open_read");
        exit(1) ;
    }

    char c;
    char last[12] = "";
    char res[4096] = "";
    int cpt = 0;
    bool fst = false;
    ssize_t rd ;

    lst = malloc(max_links * sizeof(char *) );
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
                save_lst(test , tmp, nb_links);
                free(tmp);

                fst = false;
                cpt = 0;
                nb_links++;
            } else if (cpt < sizeof(res)-1) res[cpt++] = c;
            
        }
        
    }
    free(tmp);

    if (rd == -1) {
        perror("read");
    }

    for( int i = 0; i < nb_links ; i++){
        free(lst[i]);
    }
    free(lst);
    
    printf("il y a %d liens\n",nb_links);
    printf("-> %s le 2eme\n",res);
    close(fd);
}

int get_nb_links(){
    return nb_links;
}

items * get_lst(){
    return test;
}
