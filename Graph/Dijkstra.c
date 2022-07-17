//Djikstra 算法  求单源最短路径
#include<stdio.h>
#include<stdlib.h>



#define MAX_VERNUM 10
#define INFINITY  32768

//路径数组
int path[MAX_VERNUM];

//标记数组
int visited[MAX_VERNUM];


//UDN 无向网
typedef struct graph
{
    char vertexs[MAX_VERNUM];
    int arcs[MAX_VERNUM][MAX_VERNUM];
    int vernum;
    int arcnum;
}Graph;


int Locate(Graph * G,char target){

    for (int i = 0; i < G->vernum; i++)
    {
        if (G->vertexs[i] == target)
        {
            return i;
        }
        
    }
    return -1;

}


void create_graph(Graph * G){

    printf("请分别输入顶点数,边数:");
    scanf("%d %d",&G->vernum,&G->arcnum);
    printf("请输入顶点信息:");
    for (int i = 0; i < G->vernum; i++)
    {
        scanf("%s",&G->vertexs[i]);
    }
    getchar();
    //初始化边权数组
    for (int i = 0; i < G->vernum; i++)
    {
        for (int j = 0; j < G->vernum; j++)
        {
            G->arcs[i][j]=INFINITY;
        }
        
    }
    
    printf("请输入边权信息:\n");
    for (int i = 0; i < G->arcnum; i++)
    {
        int n,m;
        n=Locate(G,getchar());
        m=Locate(G,getchar());
        getchar();
        scanf("%d",&G->arcs[n][m]);
        G->arcs[m][n]=G->arcs[n][m];
        getchar();
    }
}




//迪杰斯特拉算法

void ShortestPath_Dijkstra(Graph G,int v,int * dist){

    
    int k;
    //初始化
    for (int i = 0; i < G.vernum; i++)
    {
        dist[i]=G.arcs[v][i];
        path[i]=-1;
        visited[i]=0;
    }
    dist[v]=0;
    visited[v]=1;
    for (int i = 1; i < G.vernum; i++)
    {
        int min=INFINITY;
        //找到当前距离最短的点
        for (int j = 0;  j<G.vernum ; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                k=j;
            }
            
        }
        visited[k]=1;
        //更新最短距离
        for (int m = 0; m < G.vernum; m++)
        {
            if (!visited[m] && (min + G.arcs[k][m])< dist[m])
            {
                dist[m]=min+G.arcs[k][m];
                path[m]=k;
            }
            
        }
    }
}


//打印最短路径
void PrintPath(Graph G,int v,int i){

    if (v!=-1)
    {
        PrintPath(G,path[v],i);
        printf(" %c",G.vertexs[v]);
    }
    else
    {
        printf(" %c",G.vertexs[i]);
    }
    
}


int main(int argc, char const *argv[])
{
    int dist[MAX_VERNUM];
    int v,end,k;
    Graph G;
    create_graph(&G);
    printf("亲输入起始点与终点:");
    v=Locate(&G,getchar());
    end=Locate(&G,getchar());
    ShortestPath_Dijkstra(G,v,dist);
    printf("打印最短路径:\n");
    k=end;
    PrintPath(G,k,v);
}
