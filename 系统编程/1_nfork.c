#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int n = 5;
    int i = 0;
    pid_t pid = 0;
    printf("父进程....\n");
    for(;i < n; ++i)
    {
        pid = fork();
        if(pid == 0)
        {
            printf("子进程创建 [%d]..\n", i);
            break;
        }else if(pid > 0)
        {
            //printf("父进程\n");
        }
    }
    sleep(i);
    if(i < 5)
    {
        printf("第 [%d] 个子进程退出...\n", i + 1);
    }
    else
    {
        printf("父进程退出..\n");
    }
    return 0;
}

