//�������������
#include<stdio.h>

#include<stdlib.h>

//���������
typedef struct  bitree
{
	char data;
	struct	bitree *Lchild;
	struct	bitree *Rchild;
}BTnode,*BTree;

//���н��
typedef struct queuenode
{
	BTnode data;
	struct queuenode * next;
}QueueNode;


//��������
typedef struct queue{

	QueueNode * first;
	QueueNode * last;
}Queue;


//����������
void create_BTree(BTree * root){

	char temp;
	temp=getchar();
	if (temp==' ')
	{
		(*root)=NULL;
	}
	else{
		(*root)=(BTnode *)malloc(sizeof(BTnode));
		(*root)->data=temp;
		create_BTree(&(*root)->Lchild);
		create_BTree(&(*root)->Rchild);
	}
	

}

//��Ӳ���
void enQueue(BTnode *aux,Queue *Q){
	if (aux!=NULL)
	{
		if (Q->first==NULL)
		{
			QueueNode * temp =(QueueNode *)malloc(sizeof(QueueNode));
			temp->data=(*aux);
			temp->next=NULL;
			Q->first=temp;
			Q->last=temp;
		}
		else
		{
			QueueNode * temp =(QueueNode *)malloc(sizeof(QueueNode));
			temp->data=(*aux);
			temp->next=NULL;
			Q->last->next=temp;
			Q->last=temp;
		}
	}
}

//���Ӳ���
void deQueue(Queue *Q){
	if (Q->first==NULL)
	{
		printf("The queue is empty.\n");
	}
	else
	{
		printf("%c ",Q->first->data.data);
		Q->first=Q->first->next;
	}
}



//���г�ʼ��
void IinitQueue(Queue **Q){

	(*Q)->first=NULL;
	(*Q)->last=NULL;
}


//�������
void levelOrder(BTree T){
	Queue * Q=(Queue *)malloc(sizeof(Queue));
	IinitQueue(&Q);
	enQueue(T,Q);
	while (Q->first!=NULL)
	{
		deQueue(Q); 
		enQueue(T->Lchild,Q);
		enQueue(T->Rchild,Q);
		T=&(Q->first->data); 
	}
}



int main(int argc, char const *argv[])
{
	BTree T;
	printf("������������:");
	create_BTree(&T);
	printf("�������������:");
	levelOrder(T);	
	return 0;
}
