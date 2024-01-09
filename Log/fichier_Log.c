//
// Created by Jean-Baptiste Salanie on 28/12/2023.
//


#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include "fichier_Log.h"




char* date(){
    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    char* res = (char*) malloc(sizeof(int)*6+sizeof(char)*6);
    snprintf(res, 20, "%02d/%02d/%d %02d:%02d:%02d", local->tm_mday, local->tm_mon + 1,local->tm_year + 1900, local->tm_hour, local->tm_min, local->tm_sec);
    return res;
}

int log_file(char* String) {
    FILE* fichier = fopen("../log.txt", "a");

    if (fichier != NULL) {
        char* date_str = date();
        fprintf(fichier, "[%s] %s\n", date_str, String);

        free(date_str);
        fclose(fichier);
        return 1;
    }else{
        return 0;
    }
}

int log_file_init(){
    FILE* fichier = fopen("../log.txt", "w+");
    fclose(fichier);
    return 1;
}

