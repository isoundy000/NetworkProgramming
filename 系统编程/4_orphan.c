#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        while(1)
        {
            printf("child, pid = %d, ppid=%d\n", getpid(), getppid());
            sleep(1);
        }
    }else if(pid > 0)
    {
        printf("parent\n");
        sleep(5);
        printf("parent is die\n");
    }
    return 0;
}
//孤儿进程 父进程死亡 子进程被shell领养，不会退出
