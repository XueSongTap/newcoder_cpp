#include <sys/stat.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>


int main(){


    char buf[128];
    getcwd(buf, sizeof(buf));

    printf("当前的工作目录是: %s\n", buf);
    //change dir

    int ret = chdir("/home/acs/newcoder_cpp/lesson13");
    if(ret == -1){
        perror("chdir");
        return -1;
    }

    int fd = open("chdir.txt", O_CREAT| O_RDWR, 0664);
    if (fd == -1){
        perror("open");
        return -1;
    }

    close(fd);

    char buf1[128];

    getcwd(buf1, sizeof(buf1));
    printf("当前的工作目录是：%s\n", buf1);

    return 0;
}

