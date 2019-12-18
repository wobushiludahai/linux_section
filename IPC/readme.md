## FIFO
FIFO，也称为命名管道，它是一种文件类型。  
1、FIFO可以在无关的进程之间交换数据，与无名管道不同。  
2、FIFO有路径名与之相关联，它以一种特殊设备文件形式存在于文件系统中。  

#include <sys/stat.h>  
// 返回值：成功返回0，出错返回-1  
int mkfifo(const char *pathname, mode_t mode);  

## PIPE
管道，通常指无名管道，是 UNIX 系统IPC最古老的形式。  
1、半双工，仅能在一个方向上流动，具有固定的读端和写端  
2、只能用于具有亲缘关系的进程间的通信  
3、它可以看成是一种特殊的文件，对于它的读写也可以使用普通的read、write 等函数。但是它不是普通的文件，并不属于其他任何文件系统，并且只存在于内存中。  
4、fd[0]为读而打开，fd[1]为写而打开  

#include <unistd.h>  
int pipe(int fd[2]);    // 返回值：若成功返回0，失败返回-1  

## 消息队列  
消息队列，是消息的链接表，存放在内核中。一个消息队列由一个标识符（即队列ID）来标识。   
1、消息队列是面向记录的，其中的消息具有特定的格式以及特定的优先级。  
2、消息队列独立于发送与接收进程。进程终止时，消息队列及其内容并不会被删除。  
3、消息队列可以实现消息的随机查询,消息不一定要以先进先出的次序读取,也可以按消息的类型读取。  

#include <sys/msg.h>  
// 创建或打开消息队列：成功返回队列ID，失败返回-1  
int msgget(key_t key, int flag);  
// 添加消息：成功返回0，失败返回-1  
int msgsnd(int msqid, const void *ptr, size_t size, int flag);  
// 读取消息：成功返回消息数据的长度，失败返回-1  
int msgrcv(int msqid, void *ptr, size_t size, long type,int flag); （type参数表示类型） 
// 控制消息队列：成功返回0，失败返回-1  
int msgctl(int msqid, int cmd, struct msqid_ds *buf);  