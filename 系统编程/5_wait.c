#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
        printf("child......\n");
        sleep(2);
        //return 101;
        exit(102);
    }else if(pid > 0)
    {
        printf("parent....\n");
        int status;
        pid_t wpid = wait(&status);
        if(WIFEXITED(status))
        {
            printf("child exit with %d\n", WEXITSTATUS(status));
        }
        if(WIFSIGNALED(status))
        {
            printf("child by signal ... by %d\n",WTERMSIG(status));
        }
        printf("wait ... wpid = %d,pid = %d\n", wpid, pid);
        while(1)
        {
            sleep(1);
        }
    }
    return 0;
}
//wait 1.阻塞等待 2.回收子进程 3.传出参数，查看死亡原因
//捕捉是被谁杀死的
