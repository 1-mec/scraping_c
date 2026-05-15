#include "../header/curl.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>    
#include <unistd.h>    
#include <sys/file.h>   

void info_curl(CURLU * url, char ** fragment,char ** host,char ** password,char ** path,char ** port,char ** query,char ** scheme,char ** user,char ** zoneid){
    curl_url_get(url, CURLUPART_FRAGMENT, fragment, 0);
    curl_url_get(url, CURLUPART_HOST, host, 0);
    curl_url_get(url, CURLUPART_PASSWORD, password, 0);
    curl_url_get(url, CURLUPART_PATH, path, 0);
    curl_url_get(url, CURLUPART_PORT, port, 0);
    curl_url_get(url, CURLUPART_QUERY, query, 0);
    curl_url_get(url, CURLUPART_SCHEME, scheme, 0);
    curl_url_get(url, CURLUPART_USER, user, 0);
    curl_url_get(url, CURLUPART_ZONEID, zoneid, 0);
}

void free_curl(char ** fragment,char ** host,char ** password,char ** path,char ** port,char ** query,char ** scheme,char ** user,char ** zoneid){

    curl_free(fragment);
    curl_free(host);
    curl_free(password);
    curl_free(path);
    curl_free(port);
    curl_free(query);
    curl_free(scheme);
    curl_free(user);
    curl_free(zoneid);
}


void save_file_w_name(char * arg,char * name){

    CURL * easy = curl_easy_init();
    if (!easy) {
        printf("Server éteint ou pas de connexion\n");
        exit(1);
    }

    char * res = strcat(name ,".html");
    FILE *fp = fopen(res, "w");
    flock( fileno(fp),LOCK_EX);
    curl_easy_setopt(easy, CURLOPT_URL, arg);
    curl_easy_setopt(easy, CURLOPT_WRITEDATA, fp);
    curl_easy_perform(easy);
    flock( fileno(fp),LOCK_UN);
    fclose(fp);

    curl_easy_cleanup(easy);

}

void save_file(char * arg){
    CURL * easy = curl_easy_init();
    if (!easy) {
        printf("Server éteint ou pas de connexion\n");
        exit(1);
    }

    FILE *fp = fopen("your_page.html", "w");
    flock( fileno(fp),LOCK_EX);
    curl_easy_setopt(easy, CURLOPT_URL, arg);
    curl_easy_setopt(easy, CURLOPT_WRITEDATA, fp);
    curl_easy_perform(easy);
    flock( fileno(fp),LOCK_UN);
    fclose(fp);

    curl_easy_cleanup(easy);
}
