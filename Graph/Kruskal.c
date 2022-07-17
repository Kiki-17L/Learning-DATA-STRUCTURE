#include<stdio.h>
#define MAXVERNUM 10
#define INFINITY 65535


typedef struct 
{
    int a;
    int b;
    int weight;
}Edge;


 typedef struct graph
 {
     char vertexs[MAXVERNUM];
     int edges[MAXVERNUM][MAXVERNUM];
     int vernum;
     int edgenum;
 }Graph;


int Locate(Graph *G,char target){

    for (int i = 0; i < G->vernum; i++)
    {
        if (G->vertexs[i] == target)
        {
            return i;
        }
        
    }
    return -1;
}



void create(Graph * G){
    int n,m,weight;
    printf("请输入顶点数以及边数:");
    scanf("%d %d",&G->vernum,&G->edgenum);
    getchar();
    printf("请输入顶点信息:");
    for (int i = 0; i < G->vernum; i++)
    {
        scanf("%s",&G->vertexs[i]);
    }
    getchar();
    //初始化邻接矩阵
    for (int i = 0; i < G->vernum; i++)
    {
        for (int j = 0; j < G->vernum; j++)
        {
            if (i!=j)
            {
                G->edges[i][j]=INFINITY;
            }
            else
            {
                G->edges[i][j]=0;
            }
            
            
        }
        
    }
    printf("请输入边信息:");
    for (int i = 0; i < G->edgenum; i++)
    {
        n=Locate(G,getchar());
        m=Locate(G,getchar());
        scanf("%d",&weight);
        G->edges[n][m]=weight;
        G->edges[m][n]=weight;
        getchar();
    }
}


void ShellSort(Graph *G, Edge *a){


    for (int gap  =G->edgenum/2 ; gap>=1; gap=gap/2)
    {
        for (int i = gap; i < G->edgenum; i++)
        {
            if (a[i].weight<a[i-gap].weight)
            {
                int j;
                Edge temp=a[i];
                for ( j = i-gap; j>=0 && a[j].weight > temp.weight ; j-=gap)
                {
                    a[j+gap]=a[j];
                }
                a[j+gap]=temp;
                
            }
            
        }
        
    }
}


//查根
int getRoot(int p ,int *parent){


    while (p!=parent[p])
    {
        p=parent[p];
    }
    return p;
    


}


void Kruskal(Graph *G ){
    Edge Minedges[MAXVERNUM];
    int k=0,a,b,sum=0;
    Edge edges[G->edgenum];
    int parent[G->vernum];
    //初始化
    for (int i = 0; i < G->vernum; i++)
    {
        for (int j = i; j < G->vernum; j++)
        {
            if (G->edges[i][j]!=0 && G->edges[i][j]!=INFINITY)
            {
                edges[k].a=i;
                edges[k].b=j;
                edges[k].weight=G->edges[i][j];
                k++;
            }
            
        }
        
    }
    for (int i = 0; i < G->vernum; i++)
    {
        parent[i]=i;
    }
    
    ShellSort(G,edges);//升序排序
    for (int i = 0; i < G->edgenum; i++)
    {
        a=getRoot(edges[i].a,parent);
        b=getRoot(edges[i].b,parent);
        if (a!=b)
        {
            parent[a]=b;//并入
            printf("%c->%c:%d\n",G->vertexs[edges[i].a],G->vertexs[edges[i].b],edges[i].weight);
            sum+=edges[i].weight;        
        }
        
    }
    printf("权值和:%d\n",sum);
}

 int main(int argc, char const *argv[])
 {
     Graph G;
     create(&G);
     Kruskal(&G);
     return 0;
 }
 
 