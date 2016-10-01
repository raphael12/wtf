#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main (int argc, char ** argv)
{  
	umask(0);
	int fb=open(argv[1], O_RDONLY);
	if(fb < 0) {
		perror("");
		fprintf(stderr, "gavno\n");
		exit(1);
	} 
	char buf[1000];
	read(fb, buf, 1000);
	printf ("%s\n" , buf);
	close(fb);
	return 0;
}
