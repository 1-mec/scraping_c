#ifndef CURL_H
#define CURL_H

#include <curl/curl.h>

void info_curl(CURLU *h, char ** fragment,char ** host,char ** password,char ** path,char ** port,char ** query,char ** scheme,char ** user,char ** zoneid);
void free_curl(char ** fragment,char ** host,char ** password,char ** path,char ** port,char ** query,char ** scheme,char ** user,char ** zoneid);

void save_file(char *url);
void save_file_w_name(char *url, char *name);

#endif