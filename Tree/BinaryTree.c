#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

typedef char ElemType;



//���������
typedef struct BiTNode{

    ElemType data;
    struct BiTNode * lchild,*rchild;
}BiTNode,*BiTree;


//�ݹ鷽������һ�ö�������Լ��ǰ������
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

//���ʽ�����ݾ������
void visit(char c){

    printf("%c��\n",c);

}




int SizeOfBiTree(BiTree T){
    if (T==NULL)
    {
        return 0;
    }
    else return SizeOfBiTree(T->lchild)+SizeOfBiTree(T->rchild)+1;
}

//�ǵݹ����,����

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


//������������������Ҷ�������㷨
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
    printf("�������Ľڵ���Ϊ:%d\n",SizeOfBiTree(T));
    preorder(T);
    return 0;
}
