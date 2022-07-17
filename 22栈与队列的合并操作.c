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
	printf("0.退出\n");
	printf("1.输入S中的元素\n");
	printf("2.输入Q中的元素\n");
	printf("3.元素交替\n");
	printf("4.输出S中的元素\n");
	printf("5.输出Q中的元素\n");
	printf("--------------------------\n");
	printf("请选择0-5\n");
	for( ; ; )
	{
		scanf("%d",&i);
		getchar();
		if(i<0 || i>5)
			printf("输入错误，请重新输入\n");
		else 
			break;
	}
	return i;
}

/*  
	TODO: 向栈中插入数据
	功能：键盘输入数据，将数据插入栈中,每个元素之间用空格隔开，按回车，结束录入
		  如键盘录入1 2 3 4 5 回车，则栈数据为：1 2 3 4 5.
		  方法中不需要输出语句
	参数：sqStack *S 是需要插入的栈，int n 是插入栈的元素个数
	返回值：无。
*/
void ScanS ( sqStack *S , int n )//插入S中的元素
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
	TODO: 向队列中插入数据
	功能：键盘输入数据，将数据插入队列中,每个元素之间用空格隔开，按回车，结束录入
		  在主函数中已经声明，队列初始值都是0，将队列奇数项的值由0替换成键盘录入的值
		  在本操作中，对队列的奇数项（date[]数组下标为偶数的项，如data[0],data[2]）进行赋值，

		  如键盘录入1 2 3 4 5 回车，则插入后队列数据为：1 0 2 0 3 0 4 0 5 0.
		  方法中不需要输出语句
	参数：sqQueue *Q 是需要插入的队列，int n 是插入队列的元素个数
	返回值：无。
*/
void ScanQ(sqQueue *Q , int n)//插入Q中的元素
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
	TODO: 将栈和队列的元素进行合并
	功能：将栈和队列的元素进行合并，将栈合并到队列上，用栈的元素取代队列的偶数项
		  比如栈的元素为：1 2 3 4 5，队列元素为：5 0 4 0 3 0 2 0 1 0，则合并完成后
		  栈S的值不变，队列Q的值变为：5 1 4 2 3 3 2 4 1 5
		  方法中不需要输出语句
	参数：sqQueue *Q是合并的队列，sqStack *S 是被合并的栈，int n 是栈（队列）的元素个数
	返回值：无。
*/
void Alter(sqQueue *Q , sqStack S , int n)//元素交替
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
	TODO: 输出栈的所有元素
	功能：将栈S的元素逐个输出，每个元素用空格隔开，所有元素输出完毕后，进行换行
		  比如：栈元素为：1 2 3 4 5 ，调用输出函数，输出为：1 2 3 4 5 换行。
	参数：sqStack *S 是需要输出的栈，int n 是栈的元素个数
	返回值：无。
*/
void PrintS(sqStack S , int n)//输出S元素
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ",S.data[i]);
    }
    printf("\n");
    
       
}

/*  
	TODO: 输出队列的所有元素
	功能：将栈S的元素逐个输出，每个元素用空格隔开，所有元素输出完毕后，进行换行
	参数：sqQueue Q 是需要插出的队列，int m 是合并后的元素个数即2n
	返回值：无。
*/
void PrintQ(sqQueue Q , int m)//输出Q中的元素
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
	printf("输入S和Q中元素的个数\n");
	scanf("%d",&n);
	for( ; ; )
	{
		switch (menu())
		{
		
		case 1:
			printf("输入S中的元素\n");
			ScanS(&S,n);
			break;
		case 2:
			printf("输入Q中的元素\n");
			ScanQ(&Q,n);
			break;
		case 3:
			printf("元素交替\n ");
			Alter(&Q,S,n);
			break;
		case 4:
			printf("输出S中的元素\n");
			PrintS(S,n);
			break;
		case 5:
			printf("输出Q中的元素\n");
			PrintQ(Q,n*2);
			break;
		case 0 : 
			printf("欢迎下次使用\n");
			return;
		}
	}
}