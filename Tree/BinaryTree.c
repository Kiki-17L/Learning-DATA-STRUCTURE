#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef char ElemType;



//二叉树结点
typedef struct BiTNode{

    ElemType data;
    struct BiTNode * lchild,*rchild;
}BiTNode,*BiTree;


//递归方法创建一棵二叉树，约定前序输入
void createBiTree(BiTree *T){
    char c;
    scanf("%c",&c);

    if (' ' == c)
    {
        *T=NULL;
    }
    else
    {
        *T= (BiTree)malloc(sizeof(BiTNode));
        (*T)->data=c;
        createBiTree(&(*T)->lchild);
        createBiTree(&(*T)->rchild);
    }
    
    
}

//访问结点数据具体操作
void visit(char c){

    printf("%c在\n",c);

}




int SizeOfBiTree(BiTree T){
    if (T==NULL)
    {
        return 0;
    }
    else return SizeOfBiTree(T->lchild)+SizeOfBiTree(T->rchild)+1;
}

//非递归遍历,迭代

void Inorder(BiTree T){
    typedef struct StackNode
    {
        BiTree data[MAXSIZE];
        int top;
    }BiTreeStack;
    BiTreeStack  workstack;
    workstack.top=-1;
    BiTree P;
    int count=0;
    int M=SizeOfBiTree(T);
    P=T;
    while(count<M){
    
        while (P)
        {
            count++;
            workstack.top++;
            workstack.data[workstack.top]=P;
            P=P->lchild; 
        }
        P=workstack.data[workstack.top];
        visit(P->data);
        workstack.top--;
        P=P->rchild;
    }
    





}


//后序遍历求二叉树的子叶树分治算法
int leaf(BiTree T){

    if (!T)
    {
        return 0;
    }
    else if (T->lchild==NULL && T->rchild == NULL)
    {
        return 1;
    }
    else
    {
        return leaf(T->lchild)+leaf(T->rchild);
    }

}





int main(int argc, char const *argv[])
{
    int level =1;
    BiTree T=NULL;
    createBiTree(&T);
    printf("二叉树的节点数为:%d\n",SizeOfBiTree(T));
    preorder(T);
    return 0;
}
