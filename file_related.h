#ifndef FILE_RELATED_H
#define FILE_RELATED_H

#include "curl.h"
#include "utils.h" 

void save_log(char * fragment,char * host,char * password,char * path,char * port,char * query,char * scheme,char * user,char * zoneid);
void read_file(char *file);

#endif