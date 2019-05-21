#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <arpa/inet.h>
#include <ctype.h>


int main()
{
    //创建用于监听的套接字
    int lfd = socket(AF_INET,SOCK_STREAM,0);
    if(lfd == -1)
    {
        perror("socket error\n");
        exit(0);
    }
    //lfd 和本地IP port绑定
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(8888);
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    int ret = bind(lfd, (struct sockaddr*)&server, sizeof(server));
    if (ret == -1)
    {
        printf("绑定失败\n");
        exit(1);
    }
    //设置监听
    ret = listen(lfd, 20);
    if(ret == -1)
    {
        printf("监听失败\n");
        exit(1);
    }
    //等待并接受连接请求,连接的客户端会填充cient结构体里的数值
    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    printf("accept 阻塞进行中...\n");
    int cfd = accept(lfd, (struct sockaddr*)&client,&len);
    if(cfd == -1)
    {
        perror("accept error!\n");
        exit(1);
    }
    printf("accept successful!");
    char ipbuf[10];
    printf("client IP : %s,port: %d\n",
        inet_ntop(AF_INET, &client.sin_addr.s_addr, ipbuf, sizeof(ipbuf)),
        ntohs(client.sin_port));
    //一直通信
    while(1)
    {
        char buf[1024] = {0};
        int len = read(cfd, buf, sizeof(buf));
        if(len == -1)
        {
            perror("read error\n");
            exit(1);
        }
        else if(len == 0)
        {
            printf("客户端已断开连接\n");
            close(cfd);
            break;
        }
        else
        {
            printf("recv buf: %s", buf);
            //回复消息
            const char * sendbuf = "赶紧滚.....";
            printf("send buf : %s\n", buf);
            write(cfd, sendbuf, strlen(sendbuf));
        }
    }   
    close(lfd);
    return 0;
}

