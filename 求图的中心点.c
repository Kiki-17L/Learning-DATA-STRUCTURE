#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>
#define MaxVerNum 30//����洢��������
#define NIF 32767   //���������
#define false 0
#define true 1
typedef char VertexType; //���嶥����������ַ���
typedef int Edgetype;

/**�����ṹ��**/
typedef struct {
	VertexType vexs[MaxVerNum];/*�����*/
	Edgetype edges[MaxVerNum][MaxVerNum]; //�߱�
	int n, e;  //�������ͱ���
} MGraph;

int menu_select() {
	int sn;
	printf("-----------��ͼ�����Ķ���----------------------\n");
	printf("1����ͼ\n");
	printf("2����������۵��Լ��˷�\n");
	printf("3�˳�\n");
	printf("  ��ѡ��1--3:  ");

	for (;;)		//�˵�����ѡ��
			{
		scanf("%d", &sn);
		getchar();
		if (sn < 1 || sn > 3)
			printf("\n\t ����ѡ�����������ѡ�� 1--3�� ");
		else
			break;
	}
	return sn;
}

/*TODO: �����ڽӾ���
 ���������� ���������������ڽӾ���,��ʼ���ýڵ��Լ����Լ�Ϊ0������ΪNIF��������ʱ��������������Ȩֵ��
 ����˵����MG-MGraph��ָ�����
 ����ֵ˵������
 */
void CreatGraph(MGraph *G) { /**�ӿڲ�����ͼ�Ľṹ��ָ��**/
	int i, j, weight, k;
	printf("�������۵�����·����(����:4,5):\t");
	scanf("%d,%d", &(G->n), &(G->e));  //������������
	printf("\n���������۵�����:\t");
	for (i = 0; i < G->n; i++) {
		scanf("%s", &(G->vexs[i]));/**���붥����Ϣ**/
	}
    for (int i = 0; i < G->n; i++)
    {
        for (int j = 0; j < G->n; j++)
        {
            if (i!=j)
            {
                G->edges[i][j]=NIF;
            }
            else
            {
                G->edges[i][j]=0;
            }
            
            
        }
        
    }
    
	for (k = 0; k < G->e; k++) {
		printf("\n���������·�ߵ��������۵��Լ�·��(����:2,3,4):\t");
		scanf("%d,%d,%d", &i, &j, &weight);/**����ߵ���Ϣ**/
        G->edges[i][j]=weight;
        G->edges[j][i]=weight;
	}

}
/*TODO: Floyd������ĵ�
 ������������Floyd�㷨������ĵ�
 ����˵����G-MGraph��ָ�����
 ����ֵ˵����char�ͽڵ�
 */
char Floyd(MGraph *G) {
	int min=NIF,k;
    int dist[MaxVerNum][MaxVerNum];
    int sum[MaxVerNum]={0};
    for (int i = 0; i < G->n; i++)
    {
        for (int j = 0; j < G->n; j++)
        {
            dist[i][j]=G->edges[i][j];
        }
        
    }
    for (int w = 0; w < G->n; w++)
    {
        for (int i = 0; i < G->n; i++)
        {
            for (int j = 0; j < G->n; j++)
            {
                if (dist[i][j] > G->edges[i][w]+G->edges[w][j])
                {
                    dist[i][j]=G->edges[i][w]+G->edges[w][j];
                }
                
            }
            
        }
        
    }
    for (int i = 0; i < G->n; i++)
    {
        for (int j = 0; j < G->n; j++)
        {
            sum[i]=sum[i]+dist[i][j];
        }
        
    }
    for (int i = 0; i < G->n; i++)
    {
        if (sum[i]<min)
        {
            min=sum[i];
            k=i;
        }
        
    }
    
    
    return G->vexs[k];

}
/**************����������***************/
void main() {
	char result;
	MGraph *S;
	S = (MGraph*) malloc(sizeof(MGraph));
	for (;;)	 // ����ѭ��,ѡ��0 �˳�
			{
		switch (menu_select()) {
		case 1:
			CreatGraph(S);
			break;
		case 2:
			result = Floyd(S);
			printf("���Ĳֿ���%c\n", result);
			break;
		case 3:
			printf(" �ټ���\n");
			exit(0);
		} // switch������
	} // forѭ������
} // main()��������
