#include <stdio.h>
#include <unistd.h>

int main()
{
    execl("/home/python/Desktop/GitHub/NetworkProgramming/系统编程/2_share ", "2_share",  NULL);
    perror("exec err\n");
    return 0;
}
//成功不会向下继续执行了，实际就是代码替换了

