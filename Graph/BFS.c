//广度优先搜索
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZEofVERTEX 10

int visited[MAXSIZEofVERTEX];

typedef struct queuenode
{
	int index;
	struct queuenode * next;
}Queuenode;

typedef struct queue
{
	Queuenode * first;
	Queuenode * last;
}Queue;

typedef struct graph
{
	char vertexs[MAXSIZEofVERTEX];
	int  arcs[MAXSIZEofVERTEX][MAXSIZEofVERTEX];
	int vernum,arcnum;
}Graph;

//初始化队列
void Init_Queue(Queue **Q){

	(*Q)->first=NULL;
	(*Q)->last=NULL;
}

void EnQueue(Queue *Q,int v){

	Queuenode * p=(Queuenode *)malloc(sizeof(Queuenode));
	p->index=v;
	p->next=NULL;
	if (Q->first==NULL)
	{
		Q->first=p;
		Q->last=Q->first;
	}
	else
	{
		Q->last->next=p;
		Q->last=p;
	}
}

void DeQueue(Queue * Q){


	if (Q->first==NULL)
	{
		printf("This queue is empty.");
	}
	else
	{
		Q->first=Q->first->next;
	}
}

int Locate(Graph *G,char target){

	for (int i = 0; i < G->vernum; i++)
	{
		if (G->vertexs[i]==target)
		{
			return i;
		}
		
	}
	return -1;
}

void create(Graph *G){
	
	int n,m;
	printf("请分别输入顶点数与边数:");
	scanf("%d %d",&G->vernum,&G->arcnum);
	printf("请输入顶点:");
	getchar();
	for (int i = 0; i < G->vernum; i++)
	{
		scanf("%s",&G->vertexs[i]);
	}
	getchar();
	//初始化adj Matrix
	for (int i = 0; i < G->vernum; i++)
	{
		for (int j = 0; j < G->arcnum; j++)
		{
			G->arcs[i][j]=0;
		}
		
	}
	printf("请输入边关系:");
	for (int i = 0; i < G->arcnum; i++)
	{
		n=Locate(G,getchar());
		m=Locate(G,getchar());
		getchar();
		if (m!=-1 && n!=-1)
		{
			G->arcs[n][m]=1;
			G->arcs[m][n]=1;
		}
		else
		{
			printf("无此边");
		}
		
		
	}
}


void BFS(Graph G,Queue * Q,int v){
	visited[v]=1;
	EnQueue(Q,v);
	while (Q->first!=NULL)
	{
		v=Q->first->index;
		for (int i = 0; i < G.vernum; i++)
		{
			if ( G.arcs[v][i] && !visited[i])
			{
				visited[i]=1;
				EnQueue(Q,i);
				
			}
			
		}
		DeQueue(Q);
		printf("%c\n",G.vertexs[v]);
	}


}


void BFStraverse(Graph G,Queue *Q){

	//初始化访问队列
	for (int i = 0; i < G.vernum; i++)
	{
		visited[i]=0;
	}
	for (int i = 0; i < G.vernum; i++)
	{
		if (!visited[i])
		{
			BFS(G,Q,i);
		}
		
	}
}



int main(int argc, char const *argv[])
{
	Queue * Q=(Queue *)malloc(sizeof(Queue));
	Graph G;
	create(&G);
	Init_Queue(&Q);
	BFStraverse(G,Q);
	return 0;
}
