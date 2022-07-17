//邻接表结构


#include<stdio.h>
#include<stdlib.h>
#define MAXSIZEofVERTEX 10

//访问数组
int visited[MAXSIZEofVERTEX];


//邻接表结点
typedef struct edgenode
{
    int index;
    struct edgenode * next;
}edgenode;

//顶点结构
typedef struct datanode
{
    char data;
    edgenode * firstegde;
}datanode;


//图结构
typedef struct Graph
{
    datanode adjvertex[MAXSIZEofVERTEX];
    int vernum,arcnum;
}Graph;

int Locate(Graph G,char target){

    for (int i = 0; i < G.vernum; i++)
    {
        if (G.adjvertex[i].data==target)
        {
            return i;
        }
        
    }
    return -1;
}


void create( Graph * G){

    printf("请分别输入顶点数,边数:");
    scanf("%d %d",&G->vernum,&G->arcnum);
    getchar();
    printf("请输入结点:");
    for (int i = 0; i < G->vernum; i++)
    {
        scanf("%s",&G->adjvertex[i].data);
        G->adjvertex[i].firstegde=NULL;
    }
    getchar();
    printf("请输入边关系:");
    for (int i = 0; i < G->arcnum; i++)
    {
        int n=Locate(*G,getchar());
        int m=Locate(*G,getchar());
        getchar();
        edgenode * p=(edgenode *)malloc(sizeof(edgenode));
        p->index=m;
        p->next=G->adjvertex[n].firstegde;
        G->adjvertex[n].firstegde=p;
        edgenode * q=(edgenode *)malloc(sizeof(edgenode));
        p->index=n;
        p->next=G->adjvertex[m].firstegde;
        G->adjvertex[m].firstegde=p;
    }
}

void DFS(Graph G,int v){
    edgenode *p=G.adjvertex[v].firstegde;
    printf("%c\n",G.adjvertex[v].data);
    visited[v]=1;//标记
    while (p)
    {
        if (!visited[p->index])
        {
            DFS(G,p->index);
        }
        p=p->next;
    }
    
}








void DFStraverse(Graph G){

    //初始化访问数组
    for (int i = 0; i < G.vernum; i++)
    {
        visited[i]=0;
    }
    //若不连通，则打印连通分量
    printf("深度优先搜索:");
    for (int i = 0; i < G.vernum; i++)
    {
        if (!visited[i])
        {
            DFS(G,i);
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    Graph G;
    create(&G);
    DFStraverse(G);
    return 0;
}
