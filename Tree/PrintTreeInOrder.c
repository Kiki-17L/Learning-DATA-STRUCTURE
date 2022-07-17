//横向显示二叉树
#include<stdio.h>
#include<stdlib.h>


typedef struct BiTreeNode
{
    char data;
    struct BiTreeNode *Lchild;
    struct BiTreeNode *Rchild;
}BiTreeNode,*BiTree;



//先序创建二叉树
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


//RDL中序显示二叉树
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
    printf("建立二叉树:");
    create_BiTree(&T);
    printf("横向显示树为:\n");
    PrintTree_InOrder(T,0);
    return 0;
}

