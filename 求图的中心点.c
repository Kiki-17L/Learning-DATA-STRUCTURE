#include <stdio.h>
#include<malloc.h>
#include <stdlib.h>
#define MaxVerNum 30//定义存储的最大个数
#define NIF 32767   //定义无穷大
#define false 0
#define true 1
typedef char VertexType; //定义顶点表类型是字符型
typedef int Edgetype;

/**建立结构体**/
typedef struct {
	VertexType vexs[MaxVerNum];/*顶点表*/
	Edgetype edges[MaxVerNum][MaxVerNum]; //边表
	int n, e;  //顶点数和边数
} MGraph;

int menu_select() {
	int sn;
	printf("-----------求图的中心顶点----------------------\n");
	printf("1构建图\n");
	printf("2输出中心销售点以及运费\n");
	printf("3退出\n");
	printf("  请选择1--3:  ");

	for (;;)		//菜单功能选择
			{
		scanf("%d", &sn);
		getchar();
		if (sn < 1 || sn > 3)
			printf("\n\t 输入选择错误，请重新选择 1--3： ");
		else
			break;
	}
	return sn;
}

/*TODO: 创建邻接矩阵
 功能描述： 功能描述：创建邻接矩阵,初始设置节点自己到自己为0，其他为NIF，创建边时，根据输入设置权值。
 参数说明：MG-MGraph型指针参数
 返回值说明：无
 */
void CreatGraph(MGraph *G) { /**接口参数：图的结构体指针**/
	int i, j, weight, k;
	printf("请输销售点数和路线数(比如:4,5):\t");
	scanf("%d,%d", &(G->n), &(G->e));  //顶点数及边数
	printf("\n请输入销售点数据:\t");
	for (i = 0; i < G->n; i++) {
		scanf("%s", &(G->vexs[i]));/**输入顶点信息**/
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
		printf("\n请输入存在路线的两个销售点以及路费(比如:2,3,4):\t");
		scanf("%d,%d,%d", &i, &j, &weight);/**输入边的信息**/
        G->edges[i][j]=weight;
        G->edges[j][i]=weight;
	}

}
/*TODO: Floyd求得中心点
 功能描述：用Floyd算法求出中心点
 参数说明：G-MGraph型指针参数
 返回值说明：char型节点
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
/**************主函数部分***************/
void main() {
	char result;
	MGraph *S;
	S = (MGraph*) malloc(sizeof(MGraph));
	for (;;)	 // 无限循环,选择0 退出
			{
		switch (menu_select()) {
		case 1:
			CreatGraph(S);
			break;
		case 2:
			result = Floyd(S);
			printf("中心仓库是%c\n", result);
			break;
		case 3:
			printf(" 再见！\n");
			exit(0);
		} // switch语句结束
	} // for循环结束
} // main()函数结束
