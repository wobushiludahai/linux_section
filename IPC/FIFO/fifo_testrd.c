/*
 * @Author: your name
 * @Date: 2019-12-17 23:44:32
 * @LastEditTime : 2019-12-17 23:44:50
 * @LastEditors  : Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /linux_section/IPC/FIFO/fifo_testrd.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>

int main(void)
{
    int fd;
    int len;
    char buf[1024];

    if(mkfifo("fifo", 0666) < 0 && errno != EEXIST) //创建管道
    {
        perror("Create FIFO Failed");
    }

    if((fd = open("fifo", O_RDONLY)) < 0)
    {
        perror("Open FIFO Failed");
        exit(1);
    }

    while((len = read(fd, buf, 1024)) > 0)
    {
        printf("Read message:%s", buf);
    }

    close(fd);
    return 0;
}