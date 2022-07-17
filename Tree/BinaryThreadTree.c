#include<stdio.h>
#include<stdlib.h>


typedef enum{Link,Thread} PointerTag;

typedef char ElemType;

//树结点
typedef struct BiThrTree {
    ElemType data;
    struct BiThrTree * lchild,* rchild;
    PointerTag ltag,rtag;
}BiThrNode,*ThrTree;

//全局变量
ThrTree pre;




//创建二叉树  前序
void create_BiThrTree(ThrTree * T){
    ElemType data;
    scanf("%c",&data);
    if (' '==data)
    {
        *T=NULL;
    }
    else{
        *T=  (ThrTree)malloc(sizeof(BiThrNode));
        (*T)->data=data;
        (*T)->ltag=Link;
        (*T)->rtag=Link;
        create_BiThrTree(&(*T)->lchild);
        create_BiThrTree(&(*T)->rchild);
    }
}




//线索化二叉树  中序
void InThreading(ThrTree T){

    if (T)
    {
        InThreading(T->lchild);//左孩子遍历
        if (!T->lchild)
        {
            T->ltag =Thread;
            T->lchild=pre;
        }
        if (!pre->rchild)             //结点处理
        {
            pre->rtag=Thread;
            pre->rchild=T;
        }
        pre=T;
        InThreading(T->rchild);//右孩子遍历
    }
}


void InOrderThreading(ThrTree * p,ThrTree T)
{       
    *p=(ThrTree)malloc(sizeof(BiThrNode));
    (*p)->ltag=Link;
    (*p)->rtag=Thread;
    (*p)->rchild=*p;
    if (!T)
    {
        (*p)->lchild=*p;
    }
    else{
        (*p)->lchild=T;
        pre=(*p);
        InThreading(T);
        pre->rtag=Thread;
        pre->rchild=(*p);
        (*p)->rchild=pre;
    }
    


}




int main(int argc, char const *argv[])
{
    ThrTree P,T;
    create_BiThrTree(&T);
    InOrderThreading(&P,T);   
    return 0;
}
