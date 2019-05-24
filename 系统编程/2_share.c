#include <stdio.h>
#include <unistd.h>

int var = 100;

int main()

{
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("child_old...%d\n",var);
        var = 101;
        printf("child_new...%d\n",var);
        var = 101;
    }else if(pid > 0 )
    {
        sleep(1);
        printf("parent...%d\n",var);
    }
    return 0;
}
//父子进程 读时共享 写时复制
