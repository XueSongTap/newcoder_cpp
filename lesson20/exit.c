#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){
    printf("hello\n");

    printf("world");

    //exit(0);
    _exit(0);
    return 0;
}