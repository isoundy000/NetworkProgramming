#include <stdio.h>
#include <unistd.h>

int main()
{
    execlp("/bin/ls", "ls", "-l", "--color=auto", NULL);
    perror("exec err\n");
    return 0;
}
//成功不会向下继续执行了，实际就是代码替换了

