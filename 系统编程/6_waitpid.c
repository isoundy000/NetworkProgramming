#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

// <-1 -组id
// -1 回收任意子进程
//  0 回收和调用进程组id相同的组内的子进程
//  >0 回收指定pid
//
//  options
//  0与wait相同，也会阻塞
//  WNOHANG 如果当前没有子进程退出，会立刻返回
int main()
{
    printf("Hello world\n");
    return 0;
}

