#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    printf("Just Keep!\n");

    __pid_t pid = fork();

    if(pid == -1) {perror("fork"),exit(1);}

    printf("pid = %d, returnVal = %d\n", getpid(), pid);
    sleep(1);

    _exit(0);
}
