#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define  ERROR 0
#define OK 1
#define TURE 1
#define FAULT -1

#define MAXSIZE 100

typedef struct 
{
	int data[MAXSIZE];
	int front ;
	int rear ;
}sqQueue;

typedef struct 
{
	int  data[MAXSIZE];
	int top;
}sqStack;

int menu();
void ScanS(sqStack *S , int n);
void ScanQ(sqQueue *Q , int n);
void  Alter(sqQueue *Q , sqStack S , int n);
void PrintS(sqStack S , int n);
void PrintQ(sqQueue Q , int m);

int menu()
{
	int i;
	printf("---------------------------\n");
	printf("0.�˳�\n");
	printf("1.����S�е�Ԫ��\n");
	printf("2.����Q�е�Ԫ��\n");
	printf("3.Ԫ�ؽ���\n");
	printf("4.���S�е�Ԫ��\n");
	printf("5.���Q�е�Ԫ��\n");
	printf("--------------------------\n");
	printf("��ѡ��0-5\n");
	for( ; ; )
	{
		scanf("%d",&i);
		getchar();
		if(i<0 || i>5)
			printf("�����������������\n");
		else 
			break;
	}
	return i;
}

/*  
	TODO: ��ջ�в�������
	���ܣ������������ݣ������ݲ���ջ��,ÿ��Ԫ��֮���ÿո���������س�������¼��
		  �����¼��1 2 3 4 5 �س�����ջ����Ϊ��1 2 3 4 5.
		  �����в���Ҫ������
	������sqStack *S ����Ҫ�����ջ��int n �ǲ���ջ��Ԫ�ظ���
	����ֵ���ޡ�
*/
void ScanS ( sqStack *S , int n )//����S�е�Ԫ��
{
    int e;
	for (int i = 0; i < n; i++)
    {
        scanf("%d",&e);
        if (S->top == MAXSIZE-1)
        {
            exit(0);/* code */
        }
        S->top++;
        S->data[S->top]=e;/* code */
    }
    

}

/*  
	TODO: ������в�������
	���ܣ������������ݣ������ݲ��������,ÿ��Ԫ��֮���ÿո���������س�������¼��
		  �����������Ѿ����������г�ʼֵ����0���������������ֵ��0�滻�ɼ���¼���ֵ
		  �ڱ������У��Զ��е������date[]�����±�Ϊż�������data[0],data[2]�����и�ֵ��

		  �����¼��1 2 3 4 5 �س����������������Ϊ��1 0 2 0 3 0 4 0 5 0.
		  �����в���Ҫ������
	������sqQueue *Q ����Ҫ����Ķ��У�int n �ǲ�����е�Ԫ�ظ���
	����ֵ���ޡ�
*/
void ScanQ(sqQueue *Q , int n)//����Q�е�Ԫ��
{
    int count=0;
    while (count<n)
    {
        if (Q->rear % 2 == 0)
        {
            scanf("%d",&Q->data[Q->rear]);
            count++;
        }
        Q->rear++;   
    }
}

/*  
	TODO: ��ջ�Ͷ��е�Ԫ�ؽ��кϲ�
	���ܣ���ջ�Ͷ��е�Ԫ�ؽ��кϲ�����ջ�ϲ��������ϣ���ջ��Ԫ��ȡ�����е�ż����
		  ����ջ��Ԫ��Ϊ��1 2 3 4 5������Ԫ��Ϊ��5 0 4 0 3 0 2 0 1 0����ϲ���ɺ�
		  ջS��ֵ���䣬����Q��ֵ��Ϊ��5 1 4 2 3 3 2 4 1 5
		  �����в���Ҫ������
	������sqQueue *Q�Ǻϲ��Ķ��У�sqStack *S �Ǳ��ϲ���ջ��int n ��ջ�����У���Ԫ�ظ���
	����ֵ���ޡ�
*/
void Alter(sqQueue *Q , sqStack S , int n)//Ԫ�ؽ���
{
    int count=0;
    Q->rear=Q->front;
    while (count<n)
    {
        if (Q->rear % 2)
        {
            Q->data[Q->rear] = S.data[count++];
        }
        Q->rear++;
    }
}

/*  
	TODO: ���ջ������Ԫ��
	���ܣ���ջS��Ԫ����������ÿ��Ԫ���ÿո����������Ԫ�������Ϻ󣬽��л���
		  ���磺ջԪ��Ϊ��1 2 3 4 5 ������������������Ϊ��1 2 3 4 5 ���С�
	������sqStack *S ����Ҫ�����ջ��int n ��ջ��Ԫ�ظ���
	����ֵ���ޡ�
*/
void PrintS(sqStack S , int n)//���SԪ��
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",S.data[i]);
    }
    printf("\n");
    
       
}

/*  
	TODO: ������е�����Ԫ��
	���ܣ���ջS��Ԫ����������ÿ��Ԫ���ÿո����������Ԫ�������Ϻ󣬽��л���
	������sqQueue Q ����Ҫ����Ķ��У�int m �Ǻϲ����Ԫ�ظ�����2n
	����ֵ���ޡ�
*/
void PrintQ(sqQueue Q , int m)//���Q�е�Ԫ��
{
    for (int i = 0; i < m; i++)
    {
        printf("%d ",Q.data[i]);
    }
    printf("\n");
    
}

void main()
{
	int i;
	int n;
	sqStack S;
	sqQueue Q;
    memset(Q.data,0,MAXSIZE);
	S.top = -1;

	Q.front = 0;
	Q.rear = 0;
	printf("����S��Q��Ԫ�صĸ���\n");
	scanf("%d",&n);
	for( ; ; )
	{
		switch (menu())
		{
		
		case 1:
			printf("����S�е�Ԫ��\n");
			ScanS(&S,n);
			break;
		case 2:
			printf("����Q�е�Ԫ��\n");
			ScanQ(&Q,n);
			break;
		case 3:
			printf("Ԫ�ؽ���\n ");
			Alter(&Q,S,n);
			break;
		case 4:
			printf("���S�е�Ԫ��\n");
			PrintS(S,n);
			break;
		case 5:
			printf("���Q�е�Ԫ��\n");
			PrintQ(Q,n*2);
			break;
		case 0 : 
			printf("��ӭ�´�ʹ��\n");
			return;
		}
	}
}