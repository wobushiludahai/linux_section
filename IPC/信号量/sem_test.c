/*
 * @Description: 信号量example
 * @Author: land sea
 * @Date: 2019-12-19 18:32:13
 * @LastEditTime: 2019-12-19 20:12:18
 * @LastEditors: Please set LastEditors
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/sem.h>

//联合体，用于semctl初始化
union semun
{
    int val;
    struct semid_ds *buf;
    unsigned short *array;
};

//初始化信号量
int init_sem(int sem_id, int value)
{
    union semun tmp;
    tmp.val = value;
    if(semctl(sem_id, 0, SETVAL, tmp) == -1)
    {
        perror("Init Semaphore Error");
        return -1;
    }
    return 0;
}

//P操作
//      若信号量值为1，获取资源并将信号量值-1
//      若信号量值为0，进程挂起等待
int sem_p(int sem_id)
{
    struct sembuf sbuf;

    sbuf.sem_num = 0;   //序号
    sbuf.sem_op = -1;   //p操作
    sbuf.sem_flg = SEM_UNDO;

    if(semop(sem_id, &sbuf, 1) == -1)
    {
        perror("P operation Error");
        return -1
    }
    return 0;
}

//V操作
//      释放资源并将信号量值+1
//      如果有进程正在挂起等待，则唤醒它们
int sem_v(int sem_id)
{
    struct sembuf sbuf;

    sbuf.sem_num = 0;   //序号   
}
