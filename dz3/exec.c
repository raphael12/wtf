#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

extern char **environ;

int main (int argc, char ** argv)
{
	int fd, result;
	ssize_t ret;
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
	
	while ((ret = read (fd, &ch, 2)) > 0) {
		result = fork();
		if(result < 0){
			printf("Can\'t fork child\n");
			exit(-1);
		} else if (result > 0) {
			execl("ch:" , &ch, NULL);
			
		} 
		
	}

	if (ret < 0) {
		fprintf (stderr, "myread: Cannot read file\n");
		exit (1);
	}
	close (fd);
	exit (0);
}
