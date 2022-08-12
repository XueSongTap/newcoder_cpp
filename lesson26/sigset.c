#include <signal.h>

#include <stdio.h>


int main(){
    sigset_t set;

    sigemptyset(&set);

    int ret = sigismember(&set, SIGINT);


    if (ret == 0){
        printf("SIGINT 不阻塞\n");
    }else if (ret == 1){
        printf("SIGINT 阻塞\n");
    }

    
}