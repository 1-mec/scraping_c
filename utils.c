#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#include "curl.h"
#include "utils.h"

void aff(char * fragment,char * host,char * password,char * path,char * port,char * query,char * scheme,char * user,char * zoneid){
    printf("\nfragment -> %s,\nhost -> %s,\npassword-> %s,\npath -> %s,\nport -> %s,\nquery -> %s,\nscheme -> %s,\nuser -> %s,\nzoneid -> %s\n\n",
    fragment,host,password,path,port,query,scheme, user, zoneid);
}

char * aff_host_path_scheme(char * host,char * path,char * scheme){
    printf("---|%s|---",host);
    int len = strlen(host) + strlen(path) + strlen(scheme) +8 + strlen("hostpathscheme\n\n");
    char * res = malloc(len);
    snprintf(res,len,"scheme->%s\npath->%s\nhost->%s",scheme, path, host);
    printf("%s",res);
    return res;
}