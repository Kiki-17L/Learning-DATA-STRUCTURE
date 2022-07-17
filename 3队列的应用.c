#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100
typedef struct Node {
    char data[MAX_SIZE];
    struct Node *next;
} LinkQueueNode;

typedef struct {
    LinkQueueNode *front;
    LinkQueueNode *rear;
} LinkQueue;

/*
TODO:
  功能描述：初始化一个空的链队列
  将Q初始化为一个空的连队列Q->front = (LinkQueueNode *) malloc(sizeof(LinkQueueNode));
          判断当Q->front != NULL的时候返回1，否则返回0
  参数说明：(LinkQueue *Q) 队列的指针
  返回值 int (0或1)
*/
int IniQueue(LinkQueue *Q) {
    Q->front=Q->rear=(LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if (!Q->front)
    {
        return 0;
    }
    Q->front->next=NULL;
    return 1;
}

/*
TODO:
  功能描述：向链队列中存入若干字符串
  判断当使用函数strcpy(NewNode->data, element)向链队列中存入若干字符串
  入队成功返回1，否则返回0
  参数说明：(LinkQueue *Q, char *element)  队列的指针与入队字符串的指针
  返回值 int (0或1)
  
*/
int EnterQueue(LinkQueue *Q, char *element) {
    LinkQueueNode * NewNode;
    NewNode = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
    if (NewNode != NULL)
    {
        if (strcpy(NewNode->data,element))
        {
            NewNode->next=NULL;
            Q->rear->next=NewNode;
            Q->rear=NewNode;
            return 1;
        }
        else return 0;
        
    }
    return 0;
    

}

/*
TODO:
  功能描述：:获取队列中的倒数第K个字符串，并打印出来
  参数说明：(LinkQueue *Q, int K, int count)  队列的指针、第K个字符串与队列元素个数
   不为空返回  字符串的指针，否则返回NULL
  返回值 char * (字符串的指针或NULL)
  
*/
char *getElementByReverseOrder(LinkQueue *Q, int K, int count) {
    LinkQueueNode * p= Q->front;
    int i=0;
    while (i <= count-K)
    {
        p=p->next;
        i++;
    }
    return p->data;
}


char *s_gets(char *st, int n) {
    char *ret_val;
    char *find;
    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}

//清理列表，释放内存
void ClearQueue(LinkQueue *Q) {
    LinkQueueNode *p, *q;
    Q->rear = Q->front;
    p = Q->front->next;
    Q->front->next = NULL;
    while (p) {
        q = p;
        p = p->next;
        free(q);
    }
}


int main() {
    int i = 0;
    int count = 0;
    int K = 0;
    LinkQueue queue;
    printf("请输入要录入字符串的个数:");
    scanf("%d", &count);
    getchar();
    printf("请输入%d个字符串\n", count);
    int initcode = IniQueue(&queue);
    for (i = 0; i < count; i++) {
        char element[MAX_SIZE];
        memset(element, 0, MAX_SIZE);
        s_gets(element, MAX_SIZE);
        EnterQueue(&queue, element);
    }
    fflush(stdin);
    printf("请输入整数K，获取队列中倒数第K个字符串:");
    scanf("%d", &K);
    getchar();
    fflush(stdin);
    if (K <= 0 || K > count) {
        printf("输入的K值不合法");
        return 1;
    }
    char *elementValue = getElementByReverseOrder(&queue, K, count);
    if (elementValue != NULL) {
        printf("倒数第%d个字符串为:%s\n", K,elementValue);
    } else {
        printf("error occurs");
    }
    ClearQueue(&queue);
    return 0;
}
