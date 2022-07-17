//层序遍历二叉树
#include<stdio.h>

#include<stdlib.h>

//二叉树结点
typedef struct  bitree
{
	char data;
	struct	bitree *Lchild;
	struct	bitree *Rchild;
}BTnode,*BTree;

//队列结点
typedef struct queuenode
{
	BTnode data;
	struct queuenode * next;
}QueueNode;


//辅助队列
typedef struct queue{

	QueueNode * first;
	QueueNode * last;
}Queue;


//创建二叉树
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

//入队操作
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

//出队操作
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



//队列初始化
void IinitQueue(Queue **Q){

	(*Q)->first=NULL;
	(*Q)->last=NULL;
}


//层序遍历
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
	printf("先序建立二叉树:");
	create_BTree(&T);
	printf("层序遍历二叉树:");
	levelOrder(T);	
	return 0;
}
