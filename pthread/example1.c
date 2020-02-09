#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct
{
    int first;
    int last;
    int result;
}args_t;


int arr[5000];
int s1 = 0;
int s2 = 0;

void *myfunc(void *args)
{
    int i;
    args_t *tempargs = (args_t *)args;
    int first = tempargs->first;
    int last = tempargs->last;
    int sum = 0;

    for(i = first; i < last; i++)
    {
        sum += arr[i];
    }
    tempargs->result = sum;

    return NULL;
}


int main(void)
{
    for(int i = 0 ; i < 5000; i++)
    {
        arr[i] = rand() % 50;
    }

    pthread_t th1;
    pthread_t th2;

    args_t args1 = {0, 2500, 0};
    args_t args2 = {2500, 5000, 0};

    pthread_create(&th1, NULL, myfunc, &args1);
    pthread_create(&th2, NULL, myfunc, &args2);

    pthread_join(th1, NULL);
    pthread_join(th2, NULL);

    s1 = args1.result;
    s2 = args2.result;
    
    printf("s1 = %d\n", s1);
    printf("s2 = %d\n", s2);
    printf("s1 + s2 = %d\n", (s1+s2));
}