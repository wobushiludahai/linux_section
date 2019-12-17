#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int set = 110;
int main(void)
{
    printf("Just Keep!\n");

    pid_t pid = fork();
    if(pid < 0){ perror("fork"), exit(1);}

    if(pid == 0)
    {
        ++set;
        printf("son process pid=%d,  %d\n", getpid(), set);
    }
    else
    {
        sleep(1);
        printf("parent process pid=%d,  %d\n", getpid(), set);
    }
    
    exit(0);
}