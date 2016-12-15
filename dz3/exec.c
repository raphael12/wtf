#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

extern char **environ;

int main (int argc, char ** argv)
{
	int fd;
	char ch;
	if (argc < 2) {
		fprintf (stderr, "Too few arguments\n");
		exit (1);
	}
	fd = open (argv[1], O_RDONLY);
	if (fd < 0) {
		fprintf (stderr, "Cannot open file\n");
		exit (1);
	}	
	while (strcpy(ch, fd) != EOF) {
		 if(!fork()) { 
			execl("ch:" , &ch, NULL);
            exit(0);
        }	
	}	
	close (fd);
	exit (0);
}
