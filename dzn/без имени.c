#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(){
	    pid_t pid;
        int i, n, patya, m, p;
        scanf("%d", &n);
        patya = getpid();
        for (i = 0; i < n; ++n){
            pid = fork();
            m = getppid();
            if (m == patya){
                p = getpid();
                printf("My PID is %d\n", p);
				printf("End of child process\n");
            }
        }
        return 0;
} 
