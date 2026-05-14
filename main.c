#include <stdio.h>
#include <stdlib.h>

#include "curl.h"
#include "file_related.h"
#include "utils.h"
#include "inputs.h"

int main(){

    printf("=====================================\n");

    Params * res = malloc(sizeof(Params));  
    Params params = inputs_params();
    CURLU *h =curl_url();

    CURLUcode curl_fragment;
    CURLUcode curl_host;
    CURLUcode curl_password;
    CURLUcode curl_path;
    CURLUcode curl_port;
    CURLUcode curl_query;
    CURLUcode curl_scheme;
    CURLUcode curl_user;
    CURLUcode curl_zoneid;


    char * fragment;
    char * host;
    char * password;
    char * path;
    char * port;
    char * query;
    char * scheme;
    char * user;
    char * zoneid;

    char * url = params.result_url;
    char * file_name = params.file_name;

    printf("%s\n",url);
    printf("%s\n",file_name);

    if (params.bool_file == 1){
        save_file_w_name(url, file_name);
    } else {
        save_file(url);
    }

    printf("=================info_curl===================\n");
    info_curl(h, &fragment,&host,&password,&path,&port,&query,&scheme, &user, &zoneid);
    printf("----ok-----\n");

    printf("===================save_log=================\n");
    save_log( &fragment,&host,&password,&path,&port,&query,&scheme, &user, &zoneid);
    printf("----ok-----\n");

    printf("====================aff================\n");
    aff( &fragment,&host,&password,&path,&port,&query,&scheme, &user, &zoneid);
    printf("----ok-----\n");

    printf("=====================read_file=================\narg = %s \n",url);
    read_file(file_name);
    printf("----ok-----\n");

    printf("================free_curl====================\n");
    free_curl(fragment,host,password,path,port,query,scheme, user, zoneid);
    printf("----ok-----\n");

    printf("===================free_rc=================\n");
    free(res);
    printf("----ok-----\n");

    printf("=================free_params===================\n");
    curl_url_cleanup(h);
    printf("----ok-----\n");

    printf("====================================\n");


    return 0;
}