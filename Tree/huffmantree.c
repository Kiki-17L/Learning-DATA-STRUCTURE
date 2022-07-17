#include<stdio.h>
#include<windows.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 256


//huffman树结点
typedef struct htNode{

    char symbol;
    struct  htNode *lchild;
    struct  htNode *rchild;

}htNode;
#define TYPE htNode *

//huffman树
typedef struct huffmantree
{
    htNode *root;
}hfTree;

//table结点
typedef struct hlNode{
    char symble;
    char *code;
    struct hlNode *next;

}hlNode;


//huffman table
typedef struct huffmantable
{
    hlNode *first;
    hlNode *last;
}hfTable;




//优先队列结点
typedef struct pQueueNode
{
    TYPE val;
    int priority;
    struct pQueueNode* next;
}pQueueNode;



//优先队列
typedef struct pQueue{

    int size;
    pQueueNode * first;
}pQueue;



//初始化队列
void InitQueue(pQueue ** p){
    (*p)=(pQueue *)malloc(sizeof(pQueue));
    (*p)->first=NULL;
    (*p)->size=0;
}


//填充队列
void addQueue(pQueue **p,TYPE val,int priority)
{
    if((*p)->size==MAXSIZE)
    {
        printf("Queue is full.\n");
        return;
    }
    pQueueNode * aux=(pQueueNode*)malloc(sizeof(pQueueNode));
    aux->priority=priority;
    aux->val=val;
    //连接部分
    if((*p)->size==0 || (*p)->first==NULL)
    {
        aux->next=NULL;
        (*p)->first=aux;
        (*p)->size=1;
        return;
    }
    else{

        if (aux->priority<=(*p)->first->priority)
        {
            aux->next=(*p)->first;
            (*p)->first=aux;
            (*p)->size++;
            return;
        }
        else
        {
            pQueueNode *iterator =(*p)->first;
            while (iterator->next)
            {
                if (priority<=iterator->next->priority)
                {
                    aux->next=iterator->next;
                    iterator->next=aux;
                    (*p)->size++;
                    return;
                }
                iterator=iterator->next;
            }
            if (iterator->next==NULL)
            {
                aux->next=NULL;
                iterator->next=aux;
                (*p)->size++;
                return;
            }
            
            
        }
        
        
    }



}

//获取结点
TYPE getQueue(pQueue** p){

    TYPE returnvalue=NULL;
    if ((*p)->size>0)
    {
        returnvalue=(*p)->first->val;
        (*p)->first=(*p)->first->next;
        (*p)->size--;        
    }
    else{

        printf("Queue is empty.\n");
    }
    
    return returnvalue;
}





//创建huffman树
hfTree* build_huffman_tree(char *input_string)
{
    int possibility[MAXSIZE];
    for (int i = 0; i < MAXSIZE; i++)
    {
        possibility[i]=0;
    }
    //遍历字符串，记录出现次数
    for (int i = 0; input_string[i] !='\0'; i++)
    {
        possibility[input_string[i]]++;
    }
    pQueue *huffmanQueue;
    //初始化队列
    InitQueue(&huffmanQueue);
    //填充队列
    for (int k = 0; k <256; k++)
    {
        if (possibility[k])
        {
            htNode *aux=(htNode *)malloc(sizeof(htNode));
            aux->lchild=NULL;
            aux->rchild=NULL;
            aux->symbol=(char)k;
            addQueue(&huffmanQueue,aux,possibility[k]);
        }
        
    }    
    //生成huffman树
    while (huffmanQueue->size>1)
    {
        int priority=huffmanQueue->first->priority;
        priority+=huffmanQueue->first->next->priority;
        htNode *left=getQueue(&huffmanQueue);
        htNode *right=getQueue(&huffmanQueue);
        htNode *NewNode=(htNode *)malloc(sizeof(htNode));
        NewNode->lchild=left;
        NewNode->rchild=right;
        addQueue(&huffmanQueue,NewNode,priority);
    }
    hfTree *tree=(hfTree*)malloc(sizeof(hfTree));
    tree->root=getQueue(&huffmanQueue);
    return tree;
}


//前序遍历huffman树
void traverse_huffman_Tree(htNode * root,hfTable **table,int k,char *code){

    if (root->lchild==NULL && root->rchild==NULL)
    {
        if (k==0)
        {
            code[k]='0';
            k++;
        }
        code[k]='\0';
        hlNode * aux=(hlNode*)malloc(sizeof(hlNode));
        aux->next=NULL;
        aux->symble=root->symbol;
        aux->code=(char *)malloc(sizeof(char)*(k+1));
        strcpy(aux->code,code); 
        if ((*table)->first==NULL &&(*table)->last==NULL)
        {
            
            (*table)->first=aux;
            (*table)->last=aux;
        }
        else{
            (*table)->last->next=aux;
            (*table)->last=aux;
        }
        
    }
    if (root->lchild!=NULL)
    {
        code[k]='0';
        traverse_huffman_Tree(root->lchild,table,k+1,code);
    }
    if (root->rchild!=NULL)
    {
        code[k]='1';
        traverse_huffman_Tree(root->rchild,table,k+1,code);
    }
    
    
    
}



//创建huffman table
hfTable* build_huffman_table( hfTree* huffmantree){

    hfTable * table=(hfTable*)malloc(sizeof(hfTable));
    table->first=NULL;
    table->last=NULL;
    char code[MAXSIZE]="0";
    int k=0;
    traverse_huffman_Tree(huffmantree->root,&table,k,code);
    return table;
}




void Encode(hfTable *codetable,char *input_string,char *encoded_string){

    hlNode * traversal;
    printf("Encoding....\n\nInput String:\n%s\nEncoded String:\n",input_string);
    for (int i = 0; input_string[i]!='\0'; i++)
    {
        traversal=codetable->first;
        while (traversal->symble!=input_string[i])
        {
            traversal=traversal->next;
        }
        strcat(encoded_string,traversal->code);
    }
}

//解码
void Decode(hfTree * codetree,char *encoded_string,char * decoded_string){
    int k=0;
    htNode *traversal = codetree->root;
    printf("\n\nDecoding....\n\nDecoded String:\n");
    if (codetree->root->lchild==NULL && codetree->root->rchild==NULL)
    {
        for (int i = 0; encoded_string[i]!='\0'; i++)
        {
            printf("%c",codetree->root->symbol);
            decoded_string[k]=codetree->root->symbol;
            k++;
        }
    }
    else{
        for (int i = 0; encoded_string[i]!='\0'; i++)
        {
            if (traversal->lchild==NULL && traversal->rchild==NULL)
            {
                printf("%c",traversal->symbol);
                decoded_string[k]=traversal->symbol;
                k++;
                traversal=codetree->root;
            }
            if (encoded_string[i]=='0')
            {
                traversal=traversal->lchild;
            }
            if (encoded_string[i]=='1')
            {
                traversal=traversal->rchild;
            }
        }
        if (traversal->lchild==NULL && traversal->rchild==NULL)
        {
            printf("%c",traversal->symbol);
            decoded_string[k]=traversal->symbol;
        }
        
        printf("\n");
    }


}


int main(int argc, char const *argv[])
{
    char decoded_string[256]={'\0'};
    char encoded_string[256]={'\0'};
    char input_string[256];
    printf("请输入要编码的字符串:");
    gets(input_string);
    hfTree *codetree=build_huffman_tree(input_string);
    hfTable *codetable=build_huffman_table(codetree);
    //打印tabel
    hlNode *iterator=codetable->first;
    while (iterator)
    {
        printf(" \"%c\",%s",iterator->symble,iterator->code);
        iterator=iterator->next;
    }
    printf("\n");
    Encode(codetable,input_string,encoded_string);
    printf("%s\n",encoded_string);
    Decode(codetree,encoded_string,decoded_string);
    return 0;
}
