#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int main(int argc, char* argv[], char* envp[]) {
	if ( argc < 2) {
		printf("lalalalalala\n");
		exit(-1);
	}
	char **arg = argv;
	while (*arg != 0) {
		printf("%s\n", *arg);
		arg++;
	}
	return 0;
}
