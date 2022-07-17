//Djikstra �㷨  ��Դ���·��
#include<stdio.h>
#include<stdlib.h>



#define MAX_VERNUM 10
#define INFINITY  32768

//·������
int path[MAX_VERNUM];

//�������
int visited[MAX_VERNUM];


//UDN ������
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

    printf("��ֱ����붥����,����:");
    scanf("%d %d",&G->vernum,&G->arcnum);
    printf("�����붥����Ϣ:");
    for (int i = 0; i < G->vernum; i++)
    {
        scanf("%s",&G->vertexs[i]);
    }
    getchar();
    //��ʼ����Ȩ����
    for (int i = 0; i < G->vernum; i++)
    {
        for (int j = 0; j < G->vernum; j++)
        {
            G->arcs[i][j]=INFINITY;
        }
        
    }
    
    printf("�������Ȩ��Ϣ:\n");
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




//�Ͻ�˹�����㷨

void ShortestPath_Dijkstra(Graph G,int v,int * dist){

    
    int k;
    //��ʼ��
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
        //�ҵ���ǰ������̵ĵ�
        for (int j = 0;  j<G.vernum ; j++)
        {
            if (!visited[j] && dist[j] < min)
            {
                min = dist[j];
                k=j;
            }
            
        }
        visited[k]=1;
        //������̾���
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


//��ӡ���·��
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
    printf("��������ʼ�����յ�:");
    v=Locate(&G,getchar());
    end=Locate(&G,getchar());
    ShortestPath_Dijkstra(G,v,dist);
    printf("��ӡ���·��:\n");
    k=end;
    PrintPath(G,k,v);
}
