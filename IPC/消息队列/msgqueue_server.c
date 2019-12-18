/*
 * @Description: x消息队列示例服务端
 * @Author: land sea
 * @Date: 2019-12-18 08:47:50
 * @LastEditTime: 2019-12-18 09:20:39
 * @LastEditors: Please set LastEditors
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <unistd.h>

//创建一个key

#define MSG_FILE "."

//消息结构体
struct  msg_form
{
    long mtype;
    char mtext[256];
};

int main(void)
{
    int msqid;
    key_t key;
    struct msg_form msg;

    //获取key值
    if((key = ftok(MSG_FILE, 'z')) < 0)
    {
        perror("ftok");
        exit(1);
    }

    //打印key值
    printf("Message Queue - Server key is %d.\n", key);

    //创建消息队列
    if((msqid = msgget(key, IPC_CREAT|0777)) == -1)
    {
        perror("msgget");
        exit(1);
    }

    //打印消息队列ID以及进程ID
    printf("My msqid is: %d.\n", msqid);
    printf("My pid is: %d.\n", getpid());

    //循环读取消息
    for(;;)
    {
        msgrcv(msqid, &msg, 256, 888, 0);
        printf("Server: receive msg.mtext is: %s.\n", msg.mtext);
        printf("Server: receive msg.mtype is: %d.\n", msg.mtype);

        //客户端接收的消息类型
        msg.mtype = 999;
        sprintf(msg.mtext, "Server msg: Just Keep!!! %d", getpid());
        msgsnd(msqid, &msg, sizeof(msg.mtext), 0);
    }

    return 0;
}
