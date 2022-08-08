/*
    int pipe(int pipefd[])
*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){

    int pipefd[2];
    int ret = pipe(pipefd);

    if (ret == -1){
        perror("pipe");

        exit(0);
    }

    pid_t  pid= fork();

    if (pid > 0){
        printf("i am parent process, pid : %d\n", getpid());
        char buf[1024] = {0};


        while (1){
            int len = read(pipefd[0], buf, sizeof(buf));
            printf("parent recv: %s, pid : %d\n", buf, getpid());

            char * str = "hello, i am child";

            write(pipefd[1], str, strlen(str));

            sleep(1);
             


        }
         
    }else if (pid == 0){
        

        printf("i am a child process, pid : %d\n", getpid());
        

        while (1){
            char * str = "hello, i am child\n";
            write(pipefd[1], str, strlen(str));
        
             
        }
       
    }

    return 0;
}  