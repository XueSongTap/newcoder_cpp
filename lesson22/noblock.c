#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main(){

    int pipefd[2];
    int ret = pipe(pipefd);

    if (ret == -1){
        perror("pipe");

        exit(0);
    }
    pid_t pid = fork();

    if (pid > 0){
        printf("i am parent process, pid :%d\n", getpid());

        close(pipefd[1]);

        char buf[1024] = {0};
        int flags = fcntl(pipefd[0], F_GETFL);
    
        flags |=  O_NONBLOCK;
        fcntl(pipefd[0], F_SETFL, flags);


    }else if (pid == 0){
        printf("i am child process, pid : %d\n", getpid());

        close(pipefd[0]);
        

        char buf[1024] = {0};

        while (1){

            char * str = "hello, i am child";


            write(pipefd[1], str, strlen(str));
            sleep(5);

        }
        
    }

    return 0;
}