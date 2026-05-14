#ifndef INPUTS_H
#define INPUTS_H

typedef struct{
    int bool_url;
    char result_url[1024];
    char rep[16];
    int bool_file;
    char file_name[32];
} Params;

Params inputs_params(void);
void clear_inputs(Params);
int verif_url_input(Params);
int verif_file_input(Params);

#endif