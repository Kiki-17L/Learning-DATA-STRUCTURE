#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define OVERFLOW -2
#define INFEASIBLE -1
#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0
#define MAXQSIZE 10

typedef char QElemType;
typedef struct SqQueue {
	QElemType *base;
	int front;
	int rear;
} SqQueue;

int InitQueue(SqQueue *Q) { // 构造一个空队列Q
	Q->base = (QElemType *) malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q->base) // 存储分配失败
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}

int QueueEmpty(SqQueue Q) { // 若队列Q为空队列,则返回TRUE,否则返回FALSE
	if (Q.front == Q.rear) // 队列空的标志
		return TRUE;
	else
		return FALSE;
}
/*TODO:插入队列
功能说明：插入元素e为Q的新的队尾元素
参数说明：Q-SqQueue类型的结构体
e-QElemType类型的参数
返回值说明：OK：成功插入队列，ERROR：插入队列失败，队列满
*/
int EnQueue(SqQueue *Q, QElemType e) { // 插入元素e为Q的新的队尾元素
    
    if(Q->rear-Q->front==MAXQSIZE) return ERROR;
    *(Q->base+Q->rear)=e;
    Q->rear++;
    return OK;
    
}  

/*TODO:出队列
功能说明：若队列不空,则删除Q的队头元素,用e返回其值,并返回OK;否则返回ERROR
参数说明：Q-SqQueue类型的结构体
e-QElemType类型的参数
返回值说明：OK：出队成功，ERROR：出队失败
*/ 
int DeQueue(SqQueue *Q, QElemType *e) { // 若队列不空,则删除Q的队头元素,用e返回其值,并返回OK;否则返回ERROR

    if (Q->front==Q->rear)
    {
        return ERROR;
    }
    *e=*(Q->base+Q->front);
    Q->front++;
    return OK;
    

}

void main() { //模拟键盘输入循环缓冲区
	char ch1, ch2;
	SqQueue Q;
	int f;
	InitQueue(&Q);
	for (;;){
		printf("第1个进程等待输入!\n");
		//第1个进程
		for (;;) {
			scanf("%s", &ch1);
			if (ch1) {
				if (ch1 == ',' || ch1 == ';' || ch1 == '.')
					break; //第1个进程正常中断
				f = EnQueue(&Q, ch1);
				//循环队列满时强制中断第1个进程
				if (f == ERROR) {
					printf("循环队列已满!\n");
					break;
				}
			}

		}
		printf("第2个进程，显示输入缓冲区的内容!\n");
		while (!QueueEmpty(Q)) //第2个进程
		{
			DeQueue(&Q, &ch2);
			putchar(ch2);  //显示输入缓冲区的内容

		}
		putchar('\n');
		if (ch1 == '.') {
			break;
		}
	}
}
