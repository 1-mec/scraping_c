#include <stdio.h>  
#include <string.h> 
#include <stdlib.h>

#include "../header/inputs.h"

Params inputs_params(){
    Params * res = malloc(sizeof(Params));  
    printf("Voulez vous mettre une url ou laisser \"https://github.com\" ? (url de base)\n(réponse par oui ou non)\n-> ");
    char * test = fgets(res->rep ,sizeof(res->rep),stdin);
    strtok(test,"\n");
    printf("--%s--\n",test);
    if ( strcmp(test,"oui") == 0){
        res->bool_url = 1 ;
        char url[1024];
        printf("Mettez votre url\n");
        char * tmp = fgets(url,1024,stdin);
        strtok(tmp,"\n");
        printf("--%s--\n",tmp);
        strcpy(res->result_url,tmp); 
        printf("--%s--\n",test);
    } else {
        res->bool_url = 0 ;
        strcpy(res->result_url,"https://github.com");
    }

    strcpy(res->rep, "");

    printf("Voulez vous mettre le contenu de la page dans un fichier que vous nommez ou laisser \"your_page.html\" ? (fichier de base)\n(réponse par oui ou non)\n-> ");
    test = fgets(res->rep ,sizeof(res->rep),stdin);
    strtok(test,"\n");
    printf("--%s--\n",test);

    if ( strcmp(test,"oui") == 0){
        res->bool_file = 1 ;
        printf("Entrez votre nom de fichier\n");
        char file[32];
        char * tmp = fgets(file,32,stdin);
        strtok(tmp,"\n");
        strcpy(res->file_name,tmp);
    } else {
        res->bool_file = 0 ;
        strcpy(res->file_name,"your_page.html");
    }
    printf("====================================\n");
    return * res;
}