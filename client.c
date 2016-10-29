#include <stdio.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

static const uint16_t SRV_PORT = 65000;

static const char* STOP_WORD = "HOY! hEy LaLA LEY!";
static const char* TERMINATE_CMD = "/terminate";

void fillServAddr(const char *ip, struct sockaddr_in* servAddr);

void readIpAddress(char *ip);

int main() {
    char ip[16];
    readIpAddress(ip);

    struct sockaddr_in servAddr;
    fillServAddr(ip, &servAddr);

    char buf[256];
    while (1) {
        int sd = socket(AF_INET, SOCK_STREAM, 0);
        if (sd < 0) {
            perror("socket() fail");
            exit(1);
        }

        if (connect(sd, (const struct sockaddr *) &servAddr, sizeof(servAddr)) < 0) {
            perror("connect() fail");
            close(sd);
            exit(1);
        }

        bzero(buf, 256);
        fgets(buf, 255, stdin);
        if (!strncmp(buf, TERMINATE_CMD, strlen(TERMINATE_CMD))) {
            if (write(sd, STOP_WORD, strlen(STOP_WORD)) < 0) {
                perror("write() stop word fail");
                close(sd);
                exit(1);
            }
            printf("Termination command sent. Exiting...\n");
            break;
        }
        if (write(sd, buf, strlen(buf)) < 0) {
            perror("write() fail");
            close(sd);
            exit(1);
        }
        printf("me->%s:\n %s\n", inet_ntoa(servAddr.sin_addr), buf);
        close(sd);
    }
    return 0;
}

void readIpAddress(char *ip) {
    bzero(ip, 16);
    printf("Enter ip address:\n");
    fgets(ip, 15, stdin);
}

void fillServAddr(const char *ip, struct sockaddr_in *servAddr) {
    bzero(servAddr, sizeof(*servAddr));
    (*servAddr).sin_family = AF_INET;
    (*servAddr).sin_addr.s_addr = inet_addr(ip);
    (*servAddr).sin_port = htons(SRV_PORT);
}
