#include<stdio.h>
#include<stdlib.h>
#define INFINITY 65535
#define maxvernum 10

//�߱�ṹ
typedef struct arc
{
    int index;
    struct arc * next;
}arc;



//��ͷ�ṹ
typedef struct AOV
{
    int indeg;
    char vertex;
    struct arc * first;
}DGraph;


int Locate(DGraph * G,char target,int vernum){


    for (int i = 0; i < vernum; i++)
    {
        if (G[i].vertex==target)
        {
            return i;
        }
    }
    
    return -1;


}

void createGraph(DGraph * G){
    int vernum,arcnum;
    printf("�����붥�����Լ�����:");
    scanf("%d %d",&vernum,&arcnum);
    getchar();
    printf("�����붥����Ϣ:");
    for (int i = 0; i < vernum; i++)
    {
        G[i].vertex=getchar();
    }
    getchar();
    //��ʼ��ͼ
    for (int i = 0; i < vernum; i++)
    {
        G[i].first=NULL;
        G[i].indeg=0;
    }
    printf("���������Ϣ:");
    for (int i = 0; i < arcnum; i++)
    {
        int arcs,arce;
        arcs=Locate(G,getchar(),vernum);
        arce=Locate(G,getchar(),vernum);
        if(G[arcs].firstG[arcs].first==NULL)
        {
            arc * p =(arc *)malloc(sizeof(arc));
            p->index=arce;
            p->next=NULL;
            G[arcs].first=p;
        }
        else
        {
             arc * p =(arc *)malloc(sizeof(arc));
            p->index=arce;
            p->next=G[arcs].first;
            G[arcs].first=p;
        }
        G[arce].indeg++;
        getchar();
    }
}

TopologicSort(DGraph * G,int vernum){

    int stack[maxvernum];
    int top=-1;
    for (int i = 0; i < vernum; i++)
    {
        if(G[i].indeg==0){

        


        }


    }
    



    
}



int main(int argc, char const *argv[])
{
    
    return 0;
}
