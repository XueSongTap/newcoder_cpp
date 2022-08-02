
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>


int main(){

    //int fd = open("1.txt", O_RDONLY);

    //fcntl(fd, F_DUPFD);
    
    int fd =  open("1.txt", O_RDWR);

    if (fd ==  -1){
        perror("open");
        return -1;
    }
    int flag = fcntl(fd, F_GETFL);
    if(flag == -1) {
        perror("fcntl");
        return -1;
    }
    flag |= O_APPEND;
    int ret = fcntl(fd, F_SETFL, flag);
    if (ret == -1){
        perror("fnctl");
        return -1;
    }

    char  * str = "hello";
    write(fd, str, strlen(str));

    close(fd);
    return 0;
}
