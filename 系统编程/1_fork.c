#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
    printf("Begin...\n");
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork error\n");
        exit(1);
    }else if(pid == 0)
    {
        printf("子进程运行中...pid = %d, ppid = %d\n", getpid(), getppid());
    }else if(pid > 0)
    {
        printf("父进程运行中... childpid = %d , pid = %d, ppid = %d\n", pid, getpid(), getppid());
    }
    printf("End...\n");
    while(1){
        sleep(1);
    }
    return 0;
}

