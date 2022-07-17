#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define ERROR -1


#define MAX_NAME 10


typedef struct Node
{
	char name[MAX_NAME];//选手姓名
	int num;//选手编号
	int score;//选手得分
	int tax; //选手名次
}Node,Vore;


int Menu(void);//菜单控制系统
int Input_Vore(Vore member[9]);//选手信息录入
void Count_Vore(Vore member[9],int number);//观众投票
int Rank_Vore(Vore member[9],int number);//结果公示


int main(void)
{
	int number=0;//参赛选手的个数，初始化为0
	Vore member[9];
	for(;;)
	{
		switch(Menu())
		{
		case 1:
			
			number=Input_Vore(member);
			break;
		case 2:
			
			Count_Vore(&member,number);
			break;
		case 3:
			
			Rank_Vore(&member,number);
			break;
		case 0:
			
			printf("感谢您的使用,再见.\n");
			return 0;
		default:
			printf("输入错误!\n请重试!\n");
			break;
		}
	}
	return 0;
}


int Menu(void)
//函数功能:菜单控制系统
//函数参数:无
//函数返回值:进行操作的序号
{
	int Entry;
	printf("========================\n");
	printf("         菜单 \n");
	printf("    1、选手信息\n");
	printf("    2、投票环节\n");
	printf("    3、结果公示\n");
	printf("    0、退出程序\n");
	printf("========================\n");
	printf("请输入对应编号进行操作(0-3):\n");
	scanf("%d",&Entry);
	return Entry;
}


int Input_Vore(Vore member[9])
//函数功能:参赛人员信息录入
//函数参数:保存信息的数组member一重指针
//函数返回值:参赛选手个数
{
	int i;//控制循环
	int number;//参赛选手个数
	printf("请输入参赛选手的人数(1-9):\n");
	scanf("%d",&number);
	for(;;)
	{
		if(number>=1 && number<=9)
		{
			for(i=0;i<number;i++)
			{
				if(i==0)
				{
					printf("============================\n");
				}
				printf("请输入第%d个选手的信息:\n",i+1);
				printf("选手姓名:");
				scanf("%s",member[i].name);
				printf("选手编号:");
				scanf("%d",&member[i].num);
				member[i].score = 0;
				printf("============================\n");
			}
			
			return number;
		}
		else
		{
			
			printf("输入错误!\n");
			printf("请重新输入!\n");
		}
	}
}


void Count_Vore(Vore member[9],int number)//观众投票
{
	int vote=1;
	int scores[9];
	int i,j;
	printf("请为喜欢的选手投票(1-%d)\n",number);
	printf("输入选手的序号(输入0时结束投票)\n");
	for(i=0;i<number;i++)
	{
		scores[i]=0;
	}

	while(vote!=0)
	{
		scanf("%d",&vote);
		if(vote!=0 && vote<=number)
		{
			member[vote-1].score++;
			printf("此次投票成功!\n");
			printf("此票为有效票!\n");
			printf("输入选手的序号(输入0时结束投票)\n");
		}
		else if(vote!=0 && vote>number)
		{
			printf("该选手不存在\n");
			printf("此票为无效票\n");
			printf("输入选手的序号(输入0时结束投票)\n");
		}
		else
		{
			printf("投票结束!\n");
		}
		printf("============================\n");
	}
	printf("观众投票结束\n");
	printf("信息统计完成\n");

	printf("\n");
}


int Rank_Vore(Vore member[9],int number)//结果公示
{
	int rank[9];//记录各个选手的排名(记录第几号是第几名，从第一名开始记录)
	
	Rank_Data(member, rank, number);

	printf("数据统计完成\n");
	printf("是否公示结果(1/0)\n");
	
	int i,j;
	int choose;
	scanf("%d",&choose);
	if(choose==0)
	{
		
		return FALSE;
	}
	//由于选手编号设定第一个人为0号，所以在进行排序时，rank[i]对应的下标就是成员录入信息时的下标
	int currRank = 1;//当前排名
	for(i=0;i<number;i++)
	{
		if(i==0)
		{
			printf("============================\n");
		}
		
		if(i > 0 && member[rank[i]].score == member[rank[i-1]].score)
		{
			printf("第%d名:\n",currRank);
			printf("姓名:%s\n",member[rank[i]].name);
			printf("编号:%d\n",member[rank[i]].num);
			printf("得分:%d\n",member[rank[i]].score);
			printf("============================\n");
		} else {
			currRank = i+1;
			if(currRank > 3) break;
			printf("第%d名:\n",currRank);
			printf("姓名:%s\n",member[rank[i]].name);
			printf("编号:%d\n",member[rank[i]].num);
			printf("得分:%d\n",member[rank[i]].score);
			printf("============================\n");
		}
	}
	
	printf("结果公示完成\n");
	printf("返回主菜单(1):");
	scanf("%d",&choose);
	
	return ;
}

/*TODO: 对投票结果进行排序
 功能描述： 对投票结果进行排序，排序结果保存在rank,rank保存第一名的序号，第二名的序号...，例如4个选手投票分数分别为2,5,9,8,则rank={2,3,1,0},注意不要修改member。
 参数说明：member选手数据
       rank排名
       number 选手总数
 返回值说明：无返回值
*/
void Rank_Data(Vore member[9],int rank[],int number)
{
	//初始化rank数组
	for (int i = 0; i < number; i++)
	{
		rank[i]=i;
	}
	//选择排序
	for (int i = 0; i < number-1; i++)
	{
		for (int j = i+1; j < number; j++)
		{
			if (member[rank[i]].score  <  member[rank[j]].score)
			{
				int temp=rank[i];
				rank[i]=rank[j];
				rank[j]=temp;
			}
			
		}
		
	}
	
}


