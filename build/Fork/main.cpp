#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{	
	printf("Begin....\n");
	pid_t pid = fork();
	if (pid < 0)
	{
		perror("for err");
		exit(1);
	}else if (pid == 0)
	{
		printf("子进程运行,pid = %d,ppid = %d\n", getpid(), getppid());
	}
	else if (pid > 0)
	{
		printf("-------------------");
		printf("父进程运行,子进程pid = %d, pid = %d,ppid = %d\n", pid, getpid(), getppid());
	}
	printf("End...\n");
    return 0;
}