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

int InitQueue(SqQueue *Q) { // ����һ���ն���Q
	Q->base = (QElemType *) malloc(MAXQSIZE * sizeof(QElemType));
	if (!Q->base) // �洢����ʧ��
		exit(OVERFLOW);
	Q->front = Q->rear = 0;
	return OK;
}

int QueueEmpty(SqQueue Q) { // ������QΪ�ն���,�򷵻�TRUE,���򷵻�FALSE
	if (Q.front == Q.rear) // ���пյı�־
		return TRUE;
	else
		return FALSE;
}
/*TODO:�������
����˵��������Ԫ��eΪQ���µĶ�βԪ��
����˵����Q-SqQueue���͵Ľṹ��
e-QElemType���͵Ĳ���
����ֵ˵����OK���ɹ�������У�ERROR���������ʧ�ܣ�������
*/
int EnQueue(SqQueue *Q, QElemType e) { // ����Ԫ��eΪQ���µĶ�βԪ��
    
    if(Q->rear-Q->front==MAXQSIZE) return ERROR;
    *(Q->base+Q->rear)=e;
    Q->rear++;
    return OK;
    
}  

/*TODO:������
����˵���������в���,��ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK;���򷵻�ERROR
����˵����Q-SqQueue���͵Ľṹ��
e-QElemType���͵Ĳ���
����ֵ˵����OK�����ӳɹ���ERROR������ʧ��
*/ 
int DeQueue(SqQueue *Q, QElemType *e) { // �����в���,��ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK;���򷵻�ERROR

    if (Q->front==Q->rear)
    {
        return ERROR;
    }
    *e=*(Q->base+Q->front);
    Q->front++;
    return OK;
    

}

void main() { //ģ���������ѭ��������
	char ch1, ch2;
	SqQueue Q;
	int f;
	InitQueue(&Q);
	for (;;){
		printf("��1�����̵ȴ�����!\n");
		//��1������
		for (;;) {
			scanf("%s", &ch1);
			if (ch1) {
				if (ch1 == ',' || ch1 == ';' || ch1 == '.')
					break; //��1�����������ж�
				f = EnQueue(&Q, ch1);
				//ѭ��������ʱǿ���жϵ�1������
				if (f == ERROR) {
					printf("ѭ����������!\n");
					break;
				}
			}

		}
		printf("��2�����̣���ʾ���뻺����������!\n");
		while (!QueueEmpty(Q)) //��2������
		{
			DeQueue(&Q, &ch2);
			putchar(ch2);  //��ʾ���뻺����������

		}
		putchar('\n');
		if (ch1 == '.') {
			break;
		}
	}
}
