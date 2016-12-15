#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    DIR *direct;
    FILE *file1;
    FILE *file2;
    
    char *a, *zero;
    a = malloc(sizeof(char)*255);
    zero = malloc(sizeof(char)*255);
    int N = 0, i = 0, j, l;
    int Number = 0, flag = 1;
    struct dirent *dp;
    scanf("%s", a);
    if((direct = opendir(a)) == 0) {
        perror("Can't open directory");
        exit(-1);
    }
    while( (dp=readdir(direct)) != NULL )
        N++;
    closedir(direct);
    char b[N][255];
    int ex[N];
    for(i = 0; i < N; i++) {
        ex[i] = 0;}
    for(i = 0; i < N; i++) {
        for(j = 0; j < strlen(a); j++) {
            b[i][j] = a[j];
        }
        b[i][strlen(a)] = '/';
        b[i][strlen(a) + 1] = '\0';
    }
    for(j = 0; j < strlen(a); j++) {
        zero[j] = a[j];
    }
    zero[strlen(a)] = '/';
    zero[strlen(a) + 1] = '.';
    zero[strlen(a) + 2] = '\0';
    i = 0;
    direct=opendir(a);
    while( (dp=readdir(direct)) != NULL ) {
        strcat(b[i], dp->d_name);
        i++;
    }
    int k = 0;
    int exFlag = 0;
    for(i = 0; i < N; i++) {
        int temp = Number;
        for( j = i + 1; j < N; j++) {
            file1 = fopen(b[i], "r");
            file2 = fopen(b[j], "r");
            fseek(file1, 0, SEEK_END);
            fseek(file2, 0, SEEK_END);
            if (i != 0) {
                for(l = 0; l < N; l++) {
                    if(ex[l] == i)
                        exFlag++;
                }
            }
            if((ftell(file1) == ftell(file2)) && (exFlag == 0)) {
                ex[k] = j;
                k++;
                if(strcmp(b[i], zero) != 0) {
                    while(!feof(file1)) {
                        if(fgetc(file1) == fgetc(file2)) {
                            flag = 0;
                            break;
                        }
                    }
                }
            }
            exFlag = 0;
            if (flag == 0)
                Number++;
            fclose(file1);
            fclose(file2);
            flag = 1;
        }
        if(Number > temp)
            Number++;
    }
    closedir(direct);
    printf("%d\n", Number);
    free(a);
    free(zero);
    return 0;
}
