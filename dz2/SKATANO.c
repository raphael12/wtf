#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//скатал у севы
extern char ** environ;

int main(int argc, char ** argv) {
    int i, k = 5;
    char *constuser = "USER=";
    char *user;
    if (argc < 1) {
        printf("Not enough arguments!\n");
        exit(-1);
    }
    
    for (i = 0; environ[i] != NULL; i++) {
        if (strncmp(environ[i], constuser, 5) == 0) {
            user = (char *)calloc((strlen(environ[i]) - 4), sizeof(char));
            while(environ[i][k] != '\0') {
                user[k-5] = environ[i][k];
                k++;
                user[k-5] = '\0';
            }
        }
    }
    
    for (i = 0; environ[i] != NULL; i++) {
        if (strstr(environ[i], user) != NULL) {
            printf("%s\n", environ[i]);
        }     
    }
    return 0;
}
