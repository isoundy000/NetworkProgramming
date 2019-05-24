#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("child\n");
    }else
    {
        printf("parent\n");
        while(1)
        {
            sleep(1);
        }
    }
    printf("dead\n");
    return 0;
}
