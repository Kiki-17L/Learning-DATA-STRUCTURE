//ѭ������
#include<stdio.h>
#include<stdlib.h>


#define MAXSIZE 5


typedef struct queue
{
    char data[MAXSIZE];
    int front;
    int rear;
}SeqQueue;

//���г�ʼ��
void Iinit_Queue(SeqQueue * Q)
{
    Q->front=0;
    Q->rear=0;
}


//��Ӻ���
void EnQueue(char aux,SeqQueue *Q){

    if ((Q->rear+1)%MAXSIZE==Q->front)
    {
        printf("��������.\n");
    }
    else
    {
        Q->data[Q->rear]=aux;
        Q->rear=(Q->rear+1)%MAXSIZE;
    }
}

//���Ӻ���
char DeQueue(SeqQueue * Q){

    char temp;
    if (Q->front==Q->rear)
    {
        printf("�����ѿ�.");
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
        printf("1.���\n2.����\n3.�˳�ϵͳ\n");
        printf("������1-3:");
        scanf("%d",&temp);
        if (temp==3)
        {
            break;
        }
        else if (temp==1)
        {
            char aux;
            printf("���:");
            scanf("%s",&aux);
            EnQueue(aux,Q);
        }
        else
        {
            printf("%c����\n",DeQueue(Q));
        }
        
        
        

    }
    
    return 0;
}
