#ifndef FILE_RELATED_H
#define FILE_RELATED_H

#include "curl.h"
#include "utils.h" 

typedef struct {
    char * lst;
    int index;
}items;

void save_log(char * fragment,char * host,char * password,char * path,char * port,char * query,char * scheme,char * user,char * zoneid);
void read_file(char *file);
int get_nb_links(void);
void save_lst(items * res , char * tmp , int index);
items * get_lst(void);
void init_lst(int max_links);
items * init_items(void);
void free_items(items * res);


#endif