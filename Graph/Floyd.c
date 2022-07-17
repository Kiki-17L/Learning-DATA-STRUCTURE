//Floyd �㷨

#include<stdio.h>
#include<stdlib.h>

#define MAX_VERNUM 10
#define INFINITY 65535


typedef struct graph
{
    char vertexs[MAX_VERNUM];
    int arcs[MAX_VERNUM][MAX_VERNUM];
    int vernum,arcnum;
}Graph;

//i->j ��̾�������
int dist[MAX_VERNUM][MAX_VERNUM];
//·������
int path[MAX_VERNUM][MAX_VERNUM];


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

void create_graph(Graph *G){

    printf("�����붥�����ͱ���:");
    scanf("%d %d",&G->vernum,&G->arcnum);
    printf("�����붥����Ϣ:");
    getchar();
    for (int i = 0; i < G->vernum; i++)
    {
        scanf("%s",&G->vertexs[i]);
    }
    getchar();
    //��ʼ��
    for (int i = 0; i < G->vernum; i++)
    {
        for (int j = 0; j < G->vernum; j++)
        {
            if (i!=j)
            {
                G->arcs[i][j]=INFINITY;
            }
            else
            {
                G->arcs[i][j]=0;
            }
        }
        
    }
    
    printf("�������,Ȩ��Ϣ:");
    for (int i = 0; i < G->arcnum; i++)
    {
        int n,m;
        n=Locate(G,getchar());
        m=Locate(G,getchar());
        scanf("%d",&G->arcs[n][m]);
        G->arcs[m][n]=G->arcs[n][m];
        getchar();
    }
    
}


void Floyd(Graph *G){
    //��ʼ����������
    for (int i = 0; i < G->vernum; i++)
    {
        for (int j = 0; j < G->vernum; j++)
        {
            dist[i][j]=G->arcs[i][j];
            path[i][j]=j;
        }
        
    }
    //wΪ�м�����
    for (int w = 0; w < G->vernum; w++)
    {
        for (int i = 0; i < G->vernum; i++)
        {
            for (int j = 0; j < G->vernum; j++)
            {
                if (dist[i][j] > G->arcs[i][w]+G->arcs[w][j])
                {
                    dist[i][j]=G->arcs[i][w]+G->arcs[w][j];
                    path[i][j]=w;
                }
                
            }
            
        }
        
    }
    



}

//��ӡ·��
void PrintPath(Graph *G,int start,int final){

    if (path[start][final]!=final)
    {
        PrintPath(G,start,path[start][final]);
        printf(" %c",G->vertexs[final]);
    }
    else
    {
        printf(" %c",G->vertexs[start]);
        printf(" %c",G->vertexs[final]);
    }
}


/*************************************������**********************************************************/
int main(int argc, char const *argv[])
{
    int start,final;
    Graph G;
    create_graph(&G);
    Floyd(&G);
    printf("���:");
    start=Locate(&G,getchar());
    getchar();
    printf("�յ�:");
    final=Locate(&G,getchar());
    PrintPath(&G,start,final);
    return 0;
}

