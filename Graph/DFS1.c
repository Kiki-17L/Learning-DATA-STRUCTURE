//�ڽӾ���ṹ
#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 10

//ͼ�ṹ
typedef struct GRAPH
{
    char vertexs[MAXSIZE];
    int arcs[MAXSIZE][MAXSIZE];
    int vernum,arcnum;
}MGraph;

//���ʱ������
int visited[MAXSIZE];

//���㶨λ����
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

//����ͼ
void create(MGraph * G){
    printf("�����������:");
    scanf("%d %d",&G->vernum,&G->arcnum);
    printf("���붥��:");
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
    printf("������߹�ϵ:");
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
    //��ʼ����������
    for (int i = 0; i < G.vernum; i++)
    {
        visited[i]=0;
    }
    //������ͨ������������ͨ����
    printf("�����������:\n");
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
