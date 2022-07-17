//�ж�����ͼ����ͨ������  ����ΰ 21421100

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ElemType char
#define ERROR -1
#define OK 1
#define TRUE 1
#define FALSE 0
#define MaxVerNum 100 

//�ڽӱ�����ݽṹ
typedef struct Node {
	int adjvex;  //�ڽӵ��±�
	struct Node *next;  //ָ����һ���ڽӵ�
} EdgeNode, *ENode;

typedef struct VNode {
	ElemType data;  //������
	ENode firstedge;  //�߱�ͷָ��
} dataNode;

typedef dataNode AdjList[MaxVerNum];

typedef struct {
	AdjList adjlist;
	int n, e;
	int vexnum, arcnum;  //���������߻���
} AlGraph;

int visited[MaxVerNum];

int menu_select();	//�˵���������
void Create(AlGraph *G);
int DFS_count(AlGraph *G,int j);
void DFSTraverse(AlGraph *G,int j);

int main() {
	int v = 0;
	int j = 0;
	AlGraph *G = (AlGraph *) malloc(sizeof(AlGraph));

	for (;;) {
		switch (menu_select()) {
		case 1:
			printf("�ڽӱ�洢����ͼ�Ľ���\n");	 //�������ĺ�������  
			Create(G);
			break;
		case 2:
			printf("�ж�����ͼ�Ƿ���ͨ\n");
			j=DFS_count(G,0);
			if(j==1) {
			printf("����ͼG����ͨͼ\n");
			}else {
			printf("����ͼG������ͨͼ\n");
			DFSTraverse(G,v);
			}
			break;
		case 0:
			printf("�ټ�!\n");				//�˳�ϵͳ
			return 0;
		} // switch������ 
	} // forѭ������ 
} // main()��������

//�˵���������
int menu_select() {
	int sn;
	printf("�ж�����ͼ����ͨ������\n");		//��ʾ�˵�
	printf("==================================\n");
	printf("1.�ڽӱ�洢����ͼ�Ľ���\n");
	printf("2.�ж�����ͼ�Ƿ���ͨ�������ͨ����\n");
	printf("0.�˳�����\n");
	printf("==================================\n");
	printf("��ѡ��0--2:");

	for (;;) {
		scanf("%d", &sn);
		getchar();
		if (sn < 0 || sn > 2)
			printf("����ѡ�����������ѡ�� 0--2");
		else
			break;
	}
	return sn;
}

// �ո�
void vBlank() {
	printf(" ");
}

// ����չʾ
void PVisit(ElemType data) {
	printf("%c ", data);
}
/*
  ��ͼ���ڽӱ��ʾ��Ϊ�洢�ṹ��������ͼ
 */
void Create(AlGraph *G) {
	int i, j, k;
	EdgeNode *s, *r;
	printf("��������������ͼ��������ͱߵĸ���(�ÿո����)\n");
	scanf("%d %d", &(G->vexnum), &(G->arcnum));
	getchar();
	
	printf("�������������Ϣ(�ÿո����)\n");
	for (i = 0; i < G->vexnum; i++) {
		scanf(" %c", &(G->adjlist[i].data));
		getchar();
		G->adjlist[i].firstedge = NULL;
	}
	
	printf("���������(Vi,Vj)�Ķ����±�(�ÿո����)\n");
	for (k = 0; k < G->arcnum; k++) {
		scanf("%d %d", &i, &j);
		s = (EdgeNode *) malloc(sizeof(EdgeNode));
		s->adjvex = j;
		s->next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = s;
		r = (EdgeNode *) malloc(sizeof(EdgeNode));
		r->adjvex = i;
		r->next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = r;
	}
}

/*  
    TODO: ��ȱ�������ͼ
    ���ܣ�ʹ�õݹ鷽�������±�i��ʼ��ȱ�������ͼ���������Ķ��㽫��Ӧvisited[i]��FALSE���TRUE
    	  �����������ṩ��PVisit(ElemType data)����������Ķ�����Ϣ��   
    ������AlGraph *G����Ҫ������ͼ��int i�ǿ�ʼ�����ĵ���±�
    ����ֵ���ޡ�
*/
void DFS(AlGraph *G, int i) {
	EdgeNode * p=G->adjlist[i].firstedge;
	visited[i]=TRUE;
	PVisit(G->adjlist[i].data);
	while (p)
	{
		if (!visited[p->adjvex])
		{
			DFS(G,p->adjvex);
		}
		
		p=p->next;
	}
	
}

void DFS_noprint(AlGraph *G, int i) {
	EdgeNode *p;
	visited[i] = TRUE;
	p=G->adjlist[i].firstedge;
	while(p) {
		if (visited[p->adjvex] == FALSE)
			DFS_noprint(G,p->adjvex);    
		p = p->next;
	}
}

/*  
    TODO: �ж�����ͼG�Ƿ���ͨ
    ���ܣ���visited[]����Ԫ��ȫ����ΪFALSE��ʹ��DFS_noprint��ͼG���б�����
    	  ͳ��DFS_noprint���������õĴ������ݹ���ʹ�õĲ��㣩��������ͳ�ƽ����
    ������AlGraph *G ����Ҫ������ͼ��int j������ͳ��DFS_noprint�����ô�������ʼֵΪ0
    ����ֵ��DFS_noprint�����ô���
*/
int DFS_count(AlGraph *G,int j) {
	//��ʼ����������
	for (int i = 0; i < G->vexnum; i++)
	{
		visited[i]=FALSE;
	}
	//��ӡ��ͨ����
	for (int i = 0; i < G->vexnum; i++)
	{
		if (!visited[i])
		{
			DFS_noprint(G,i);
			j++;
		}
		
	}
	return j;
}

/*  
    TODO: ���G����ͨ����
    ���ܣ�����visited[]�����״̬�����ĳ�FALSE��Ȼ��ʹ��DFSѭ������ͼ
    	  �����ͨ����ǰ��printf("��%d����ͨ����:", ++j)��jΪһ����������ʼֵ0
    	  ÿ�����һ����ͨ������ʹ��printf("\n")���л���
          
    ������AlGraph *G����Ҫ������ͼ��int i�Ƕ����±�
    ����ֵ���ޡ�
    ��������1����ͨ����:1 4 5 2 3
	      ��2����ͨ����:6
*/
void DFSTraverse(AlGraph *G,int i) {
	//��ʼ����������
	for (int i = 0; i < G->vexnum; i++)
	{
		visited[i]=FALSE;
	}
	//��ӡ��ͨ����
	for (int i = 0,j=0; i < G->vexnum; i++)
	{
		if (!visited[i])
		{
			printf("��%d����ͨ����:", ++j);
			DFS(G,i);
			printf("\n");
		}
		
	}
}
