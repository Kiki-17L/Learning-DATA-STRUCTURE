//邻接矩阵结构
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

//图结构
typedef struct GRAPH
{
    char vertexs[MAXSIZE];
    int arcs[MAXSIZE][MAXSIZE];
    int vernum,arcnum;
}MGraph;

//访问标记数组
int visited[MAXSIZE];

//顶点定位函数
int Locate(MGraph G,char target){

    for (int i = 0; i < G.vernum; i++)
    {
        if (G.vertexs[i]==target)
        {
            return i;
        }
        
    }
    return -1;

}

//构建图
void create(MGraph * G){
    printf("顶点数与边数:");
    scanf("%d %d",&G->vernum,&G->arcnum);
    printf("输入顶点:");
    for (int i = 0; i < G->vernum ; i++)
    {
        scanf("%s",&G->vertexs[i]);
    }
    getchar();
    for (int i = 0; i < G->vernum; i++)
    {
        for(int j=0; j< G->vernum; j++)
        {
            G->arcs[i][j]=0;
        }
    }
    printf("请输入边关系:");
    for (int i = 0; i < G->arcnum; i++)
    {
        int n,m;
        n=Locate(*G,getchar());
        m=Locate(*G,getchar());
        getchar();
        G->arcs[n][m]=1;
        G->arcs[m][n]=1;
    }
    
}
//DFS
void DFS(MGraph G,int v){

            printf("%c\n",G.vertexs[v]);
            visited[v]=1;
            for (int i = 0; i < G.vernum; i++)
            {
                if (G.arcs[v][i] && !visited[i])
                {
                    DFS(G,i);
                }
                
            }
}


void DFStraverse(MGraph G){
    //初始化访问数组
    for (int i = 0; i < G.vernum; i++)
    {
        visited[i]=0;
    }
    //若不连通，访问所有连通分量
    printf("深度优先搜索:\n");
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
    MGraph G;
    create(&G);
    DFStraverse(G);
    return 0;
}
