/*

    pid_t waitpid(pid_t pid, int *wstatus, int options)
     

    pid > 0 某个 子金城的pid
    pid = 0 回收当前进程组的pid
    pid = -1 回收所有, 相当于wait()
    pid < -1 某个进程组的id的绝对值
     
*/

#include <sys/types.h>

#include <sys/wait.h>

int main(){


}