/*
 * @Author: land sea
 * @Date: 2019-12-17 23:28:24
 * @LastEditTime : 2019-12-17 23:28:27
 * @LastEditors  : Please set LastEditors
 * @Description: a FIFO example
 *              #include <sys/stat.h>
 *              // 返回值：成功返回0，出错返回-1
 *              int mkfifo(const char *pathname, mode_t mode);
 * 
 * @FilePath: /linux_section/IPC/FIFO/fifo_test.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main(void)
{
    int fd;
    int n, i;
    char buf[1024];
    time_t tp;

    printf("I am %d process.\n", getpid());  //进程ID

    if((fd = open("fifo", O_WRONLY)) < 0)    //以写打开一个FIFO
    {
        perror("Open FIFO Failed");
        exit(1);
    }

    for(i = 0; i < 10; i++)
    {
        time(&tp);
        n = sprintf(buf,"Process %d's time is %s",getpid(),ctime(&tp));
        printf("Send message:%s", buf);     //打印
        if(write(fd, buf, n+1) < 0)
        {
            perror("Write FIFO Failed");
            close(fd);
            exit(1);
        }
        sleep(1);
    }

    close(fd);
    return 0;
}
