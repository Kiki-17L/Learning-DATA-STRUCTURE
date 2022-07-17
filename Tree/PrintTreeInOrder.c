//������ʾ������
#include<stdio.h>
#include<stdlib.h>


typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *Lchild;
    struct BiTreeNode *Rchild;
}BiTreeNode,*BiTree;



//���򴴽�������
void create_BiTree(BiTree *T){

    char temp=getchar();
    if (temp=='#')
    {
        (*T)=NULL;
    }
    else
    {
        (*T)=(BiTree)malloc(sizeof(BiTreeNode));
        (*T)->data=temp;
        create_BiTree(&(*T)->Lchild);
        create_BiTree(&(*T)->Rchild);
    }
    
}


//RDL������ʾ������
void PrintTree_InOrder(BiTree T,int level){

    if (T!=NULL)
    {
        PrintTree_InOrder(T->Rchild,level+1);
        for (int i = 0; i < level; i++)
        {
            printf("  ");
        }
        printf("%c\n",T->data);
        PrintTree_InOrder(T->Lchild,level+1);
    }
    

}


int main(int argc, char const *argv[])
{
    BiTree T;
    printf("����������:");
    create_BiTree(&T);
    printf("������ʾ��Ϊ:\n");
    PrintTree_InOrder(T,0);
    return 0;
}

