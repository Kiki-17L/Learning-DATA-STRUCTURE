#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
#define ERROR -1


#define MAX_NAME 10


typedef struct Node
{
	char name[MAX_NAME];//ѡ������
	int num;//ѡ�ֱ��
	int score;//ѡ�ֵ÷�
	int tax; //ѡ������
}Node,Vore;


int Menu(void);//�˵�����ϵͳ
int Input_Vore(Vore member[9]);//ѡ����Ϣ¼��
void Count_Vore(Vore member[9],int number);//����ͶƱ
int Rank_Vore(Vore member[9],int number);//�����ʾ


int main(void)
{
	int number=0;//����ѡ�ֵĸ�������ʼ��Ϊ0
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
			
			printf("��л����ʹ��,�ټ�.\n");
			return 0;
		default:
			printf("�������!\n������!\n");
			break;
		}
	}
	return 0;
}


int Menu(void)
//��������:�˵�����ϵͳ
//��������:��
//��������ֵ:���в��������
{
	int Entry;
	printf("========================\n");
	printf("         �˵� \n");
	printf("    1��ѡ����Ϣ\n");
	printf("    2��ͶƱ����\n");
	printf("    3�������ʾ\n");
	printf("    0���˳�����\n");
	printf("========================\n");
	printf("�������Ӧ��Ž��в���(0-3):\n");
	scanf("%d",&Entry);
	return Entry;
}


int Input_Vore(Vore member[9])
//��������:������Ա��Ϣ¼��
//��������:������Ϣ������memberһ��ָ��
//��������ֵ:����ѡ�ָ���
{
	int i;//����ѭ��
	int number;//����ѡ�ָ���
	printf("���������ѡ�ֵ�����(1-9):\n");
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
				printf("�������%d��ѡ�ֵ���Ϣ:\n",i+1);
				printf("ѡ������:");
				scanf("%s",member[i].name);
				printf("ѡ�ֱ��:");
				scanf("%d",&member[i].num);
				member[i].score = 0;
				printf("============================\n");
			}
			
			return number;
		}
		else
		{
			
			printf("�������!\n");
			printf("����������!\n");
		}
	}
}


void Count_Vore(Vore member[9],int number)//����ͶƱ
{
	int vote=1;
	int scores[9];
	int i,j;
	printf("��Ϊϲ����ѡ��ͶƱ(1-%d)\n",number);
	printf("����ѡ�ֵ����(����0ʱ����ͶƱ)\n");
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
			printf("�˴�ͶƱ�ɹ�!\n");
			printf("��ƱΪ��ЧƱ!\n");
			printf("����ѡ�ֵ����(����0ʱ����ͶƱ)\n");
		}
		else if(vote!=0 && vote>number)
		{
			printf("��ѡ�ֲ�����\n");
			printf("��ƱΪ��ЧƱ\n");
			printf("����ѡ�ֵ����(����0ʱ����ͶƱ)\n");
		}
		else
		{
			printf("ͶƱ����!\n");
		}
		printf("============================\n");
	}
	printf("����ͶƱ����\n");
	printf("��Ϣͳ�����\n");

	printf("\n");
}


int Rank_Vore(Vore member[9],int number)//�����ʾ
{
	int rank[9];//��¼����ѡ�ֵ�����(��¼�ڼ����ǵڼ������ӵ�һ����ʼ��¼)
	
	Rank_Data(member, rank, number);

	printf("����ͳ�����\n");
	printf("�Ƿ�ʾ���(1/0)\n");
	
	int i,j;
	int choose;
	scanf("%d",&choose);
	if(choose==0)
	{
		
		return FALSE;
	}
	//����ѡ�ֱ���趨��һ����Ϊ0�ţ������ڽ�������ʱ��rank[i]��Ӧ���±���ǳ�Ա¼����Ϣʱ���±�
	int currRank = 1;//��ǰ����
	for(i=0;i<number;i++)
	{
		if(i==0)
		{
			printf("============================\n");
		}
		
		if(i > 0 && member[rank[i]].score == member[rank[i-1]].score)
		{
			printf("��%d��:\n",currRank);
			printf("����:%s\n",member[rank[i]].name);
			printf("���:%d\n",member[rank[i]].num);
			printf("�÷�:%d\n",member[rank[i]].score);
			printf("============================\n");
		} else {
			currRank = i+1;
			if(currRank > 3) break;
			printf("��%d��:\n",currRank);
			printf("����:%s\n",member[rank[i]].name);
			printf("���:%d\n",member[rank[i]].num);
			printf("�÷�:%d\n",member[rank[i]].score);
			printf("============================\n");
		}
	}
	
	printf("�����ʾ���\n");
	printf("�������˵�(1):");
	scanf("%d",&choose);
	
	return ;
}

/*TODO: ��ͶƱ�����������
 ���������� ��ͶƱ�����������������������rank,rank�����һ������ţ��ڶ��������...������4��ѡ��ͶƱ�����ֱ�Ϊ2,5,9,8,��rank={2,3,1,0},ע�ⲻҪ�޸�member��
 ����˵����memberѡ������
       rank����
       number ѡ������
 ����ֵ˵�����޷���ֵ
*/
void Rank_Data(Vore member[9],int rank[],int number)
{
	//��ʼ��rank����
	for (int i = 0; i < number; i++)
	{
		rank[i]=i;
	}
	//ѡ������
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


