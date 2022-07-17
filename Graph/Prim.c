//Prim算法
#include<stdio.h>
#include<windows.h>
#define MAXVERNUM 10
#define INFINITY 65535


int parent[MAXVERNUM];
int dist[MAXVERNUM];

typedef struct graph
{
    char vertexs[MAXVERNUM];
    int edges[MAXVERNUM][MAXVERNUM];
    int vernum;
    int edgenum;
}Graph;


int Locate(Graph * G,char target){

    for (int i = 0; i < G->vernum; i++)
    {
        if (target==G->vertexs[i])
        {
            return i;
        }
        
    }
    return -1;
}

void create(Graph * G){
    int n,m,weight;
    printf("请输入顶点数与边数:");
    scanf("%d %d",&G->vernum,&G->edgenum);
    printf("请输入顶点信息:");
    for (int i = 0; i < G->vernum; i++)
    {
        scanf("%s",&G->vertexs[i]);
    }
    //初始化边矩阵
    for (int i = 0; i < G->vernum; i++)
    {
        for (int j = 0; j < G->vernum; j++)
        {
            if (i!=j)
            {
                G->edges[i][j]=INFINITY;
            }else
            {
                G->edges[i][j]=0;
            }
            
            
        }
        
    }
    getchar();
    printf("请输入边信息:");
    for (int i = 0; i < G->edgenum; i++)
    {
        n=Locate(G,getchar());
        m=Locate(G,getchar());
        scanf("%d",&weight);
        getchar();
        G->edges[n][m]=weight;
        G->edges[m][n]=weight;
    }
}


//minmal_spanning_tree
void Prim(Graph *G){

    int visited[G->vernum];
    //初始化
    for (int i = 0; i < G->vernum; i++)
    {
        visited[i]=0;
        dist[i]=G->edges[0][i];
        parent[i]=0;
    }
    visited[0]=1;
    for (int i = 1; i < G->edgenum; i++)
    {
        //选择最近的点
        int min=INFINITY;
        int k;
        for (int j = 0; j < G->vernum; j++)
        {
            if ( !visited[j] && dist[j]<min)
            {
                min=dist[j];
                k=j;
            }
            
        }
        visited[k]=1;
        //更新dist
        for (int j = 0; j < G->vernum; j++)
        {
            if (!visited[j] && dist[j]>G->edges[k][j])
            {
                dist[j]=G->edges[k][j];
                parent[j]=k;
            }
            
        }
        
        
    }
}

void Print_minmal_spanning_tree(Graph * G){
    int minweight=0;
    printf("打印最小生成树\n");
    for (int i =1; i < G->vernum ; i++)
    {
  
        printf("%c->%c:%2d\n",G->vertexs[parent[i]],G->vertexs[i],dist[i]);
        minweight+=dist[i];
    }
    printf("最小权值总和:%d\n",minweight);
    


}

int main(int argc, char const *argv[])
{
    Graph G;
    create(&G);
    Prim(&G);
    Print_minmal_spanning_tree(&G);    
    system("pause");
    return 0;
}
