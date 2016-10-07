#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
	char *error = "Error";
	char *https = "http://";
	char url[200];
	char str[200];
	int i = 0;
	int k = 0;
	scanf("%c", &str[i]);
	for(i = 0; i != NULL; i++) { //wtf????
		for(k = 0; str[k]; k++) {
			scanf("%c", &str[i]);	
		}
		if(strstr(str, error) != NULL) {
			if(strstr(str, https) != NULL) {
				strcpy(url, strstr(str, https));
				printf("%s", url);
			}
		}
		for(i=0;i<200;i++) {
			str[i] = NULL; // wtf????
		}
		k=0;
		scanf("%c", &str[i]);
	}
	return 0;
}
		
		
