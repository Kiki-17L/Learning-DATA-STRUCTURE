//判断无向图的连通性问题  梁家伟 21421100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ElemType char
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0
#define MaxVerNum 100 

//邻接表的数据结构
typedef struct Node {
	int adjvex;  //邻接点下标
	struct Node *next;  //指向下一个邻接点
} EdgeNode, *ENode;

typedef struct VNode {
	ElemType data;  //顶点域
	ENode firstedge;  //边表头指针
} dataNode;

typedef dataNode AdjList[MaxVerNum];

typedef struct {
	AdjList adjlist;
	int n, e;
	int vexnum, arcnum;  //顶点数、边弧数
} AlGraph;

int visited[MaxVerNum];

int menu_select();	//菜单驱动程序
void Create(AlGraph *G);
int DFS_count(AlGraph *G,int j);
void DFSTraverse(AlGraph *G,int j);

int main() {
	int v = 0;
	int j = 0;
	AlGraph *G = (AlGraph *) malloc(sizeof(AlGraph));

	for (;;) {
		switch (menu_select()) {
		case 1:
			printf("邻接表存储无向图的建立\n");	 //建立树的函数调用  
			Create(G);
			break;
		case 2:
			printf("判断无向图是否连通\n");
			j=DFS_count(G,0);
			if(j==1) {
			printf("无向图G是连通图\n");
			}else {
			printf("无向图G不是连通图\n");
			DFSTraverse(G,v);
			}
			break;
		case 0:
			printf("再见!\n");				//退出系统
			return 0;
		} // switch语句结束 
	} // for循环结束 
} // main()函数结束

//菜单驱动程序
int menu_select() {
	int sn;
	printf("判断无向图的连通性问题\n");		//显示菜单
	printf("==================================\n");
	printf("1.邻接表存储无向图的建立\n");
	printf("2.判断无向图是否连通，输出连通变量\n");
	printf("0.退出程序\n");
	printf("==================================\n");
	printf("请选择0--2:");

	for (;;) {
		scanf("%d", &sn);
		getchar();
		if (sn < 0 || sn > 2)
			printf("输入选择错误，请重新选择 0--2");
		else
			break;
	}
	return sn;
}

// 空格
void vBlank() {
	printf(" ");
}

// 数据展示
void PVisit(ElemType data) {
	printf("%c ", data);
}
/*
  以图的邻接表表示法为存储结构建立无向图
 */
void Create(AlGraph *G) {
	int i, j, k;
	EdgeNode *s, *r;
	printf("请依次输入无向图顶点个数和边的个数(用空格隔开)\n");
	scanf("%d %d", &(G->vexnum), &(G->arcnum));
	getchar();
	
	printf("请输入各顶点信息(用空格隔开)\n");
	for (i = 0; i < G->vexnum; i++) {
		scanf(" %c", &(G->adjlist[i].data));
		getchar();
		G->adjlist[i].firstedge = NULL;
	}
	
	printf("请输入各边(Vi,Vj)的顶点下标(用空格隔开)\n");
	for (k = 0; k < G->arcnum; k++) {
		scanf("%d %d", &i, &j);
		s = (EdgeNode *) malloc(sizeof(EdgeNode));
		s->adjvex = j;
		s->next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = s;
		r = (EdgeNode *) malloc(sizeof(EdgeNode));
		r->adjvex = i;
		r->next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = r;
	}
}

/*  
    TODO: 深度遍历无向图
    功能：使用递归方法，从下标i开始深度遍历无向图，遍历过的顶点将对应visited[i]从FALSE变成TRUE
    	  并调用上面提供的PVisit(ElemType data)输出遍历过的顶点信息。   
    参数：AlGraph *G是需要操作的图，int i是开始遍历的点的下标
    返回值：无。
*/
void DFS(AlGraph *G, int i) {
	EdgeNode * p=G->adjlist[i].firstedge;
	visited[i]=TRUE;
	PVisit(G->adjlist[i].data);
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS(G,p->adjvex);
		}
		
		p=p->next;
	}
	
}

void DFS_noprint(AlGraph *G, int i) {
	EdgeNode *p;
	visited[i] = TRUE;
	p=G->adjlist[i].firstedge;
	while(p) {
		if (visited[p->adjvex] == FALSE)
			DFS_noprint(G,p->adjvex);    
		p = p->next;
	}
}

/*  
    TODO: 判断无向图G是否连通
    功能：将visited[]数组元素全部置为FALSE，使用DFS_noprint对图G进行遍历，
    	  统计DFS_noprint方法被调用的次数（递归中使用的不算），并返回统计结果。
    参数：AlGraph *G 是需要操作的图，int j是用来统计DFS_noprint被调用次数，初始值为0
    返回值：DFS_noprint被调用次数
*/
int DFS_count(AlGraph *G,int j) {
	//初始化访问数组
	for (int i = 0; i < G->vexnum; i++)
	{
		visited[i]=FALSE;
	}
	//打印连通分量
	for (int i = 0; i < G->vexnum; i++)
	{
		if (!visited[i])
		{
			DFS_noprint(G,i);
			j++;
		}
		
	}
	return j;
}

/*  
    TODO: 输出G的连通分量
    功能：重置visited[]数组的状态，都改成FALSE，然后使用DFS循环遍历图
    	  输出连通分量前，printf("第%d个连通变量:", ++j)，j为一个变量，初始值0
    	  每输出完一个连通分量，使用printf("\n")进行换行
          
    参数：AlGraph *G是需要操作的图，int i是顶点下标
    返回值：无。
    举例：第1个连通变量:1 4 5 2 3
	      第2个连通变量:6
*/
void DFSTraverse(AlGraph *G,int i) {
	//初始化访问数组
	for (int i = 0; i < G->vexnum; i++)
	{
		visited[i]=FALSE;
	}
	//打印连通分量
	for (int i = 0,j=0; i < G->vexnum; i++)
	{
		if (!visited[i])
		{
			printf("第%d个连通变量:", ++j);
			DFS(G,i);
			printf("\n");
		}
		
	}
}
