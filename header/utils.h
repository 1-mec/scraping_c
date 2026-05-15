#ifndef UTILS_H
#define UTILS_H

#include "curl.h"

void aff(char * fragment,char * host,char * password,char * path,char * port,char * query,char * scheme,char * user,char * zoneid);
char * aff_host_path_scheme(char * host,char * path,char * scheme);

#endif