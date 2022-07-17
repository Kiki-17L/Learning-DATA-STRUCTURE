//循环队列
#include<stdio.h>
#include<stdlib.h>


#define MAXSIZE 5


typedef struct queue
{
    char data[MAXSIZE];
    int front;
    int rear;
}SeqQueue;

//队列初始化
void Iinit_Queue(SeqQueue * Q)
{
    Q->front=0;
    Q->rear=0;
}


//入队函数
void EnQueue(char aux,SeqQueue *Q){

    if ((Q->rear+1)%MAXSIZE==Q->front)
    {
        printf("队列已满.\n");
    }
    else
    {
        Q->data[Q->rear]=aux;
        Q->rear=(Q->rear+1)%MAXSIZE;
    }
}

//出队函数
char DeQueue(SeqQueue * Q){

    char temp;
    if (Q->front==Q->rear)
    {
        printf("队列已空.");
        return '0';
    }
    else
    {
        temp=Q->data[Q->front];
        Q->front=(Q->front+1)%MAXSIZE;
        return temp;
    }
}



int main(int argc, char const *argv[])
{
    SeqQueue *Q=(SeqQueue *)malloc(sizeof(SeqQueue));
    Iinit_Queue(Q);
    while (1)
    {
        int temp;
        printf("1.入队\n2.出队\n3.退出系统\n");
        printf("请输入1-3:");
        scanf("%d",&temp);
        if (temp==3)
        {
            break;
        }
        else if (temp==1)
        {
            char aux;
            printf("入队:");
            scanf("%s",&aux);
            EnQueue(aux,Q);
        }
        else
        {
            printf("%c出队\n",DeQueue(Q));
        }
        
        
        

    }
    
    return 0;
}
