/*
 * @Author: landsea
 * @Date: 2019-12-17 23:03:52
 * @LastEditTime : 2019-12-17 23:07:25
 * @LastEditors  : Please set LastEditors
 * @Description: a pipe example
 *              #include <unistd.h>
 *              int pipe(int fd[2]);    // 返回值：若成功返回0，失败返回-1
 * @FilePath: /linux_section/IPC/PIPE/pipe_test.c
 */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
    int fd[2];
    
    pid_t pid;
    char buff[20];

    if(pipe(fd) < 0)
    {
        perror("pipe");
    }

    pid = fork();
    if(pid < 0)
    {
        perror("fork");
    }

    if(pid > 0)  //父进程
    {
        close(fd[0]);   //关闭读端
        write(fd[1], "Just Keep!\n",12);
    }
    else
    {
        close(fd[1]);   //关闭写端
        read(fd[0], buff, 12);
        printf("%s", buff);
    }

    return 0;
}