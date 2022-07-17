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
  ������������ʼ��һ���յ�������
  ��Q��ʼ��Ϊһ���յ�������Q->front = (LinkQueueNode *) malloc(sizeof(LinkQueueNode));
          �жϵ�Q->front != NULL��ʱ�򷵻�1�����򷵻�0
  ����˵����(LinkQueue *Q) ���е�ָ��
  ����ֵ int (0��1)
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
  �������������������д��������ַ���
  �жϵ�ʹ�ú���strcpy(NewNode->data, element)���������д��������ַ���
  ��ӳɹ�����1�����򷵻�0
  ����˵����(LinkQueue *Q, char *element)  ���е�ָ��������ַ�����ָ��
  ����ֵ int (0��1)
  
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
  ����������:��ȡ�����еĵ�����K���ַ���������ӡ����
  ����˵����(LinkQueue *Q, int K, int count)  ���е�ָ�롢��K���ַ��������Ԫ�ظ���
   ��Ϊ�շ���  �ַ�����ָ�룬���򷵻�NULL
  ����ֵ char * (�ַ�����ָ���NULL)
  
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

//�����б��ͷ��ڴ�
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
    printf("������Ҫ¼���ַ����ĸ���:");
    scanf("%d", &count);
    getchar();
    printf("������%d���ַ���\n", count);
    int initcode = IniQueue(&queue);
    for (i = 0; i < count; i++) {
        char element[MAX_SIZE];
        memset(element, 0, MAX_SIZE);
        s_gets(element, MAX_SIZE);
        EnterQueue(&queue, element);
    }
    fflush(stdin);
    printf("����������K����ȡ�����е�����K���ַ���:");
    scanf("%d", &K);
    getchar();
    fflush(stdin);
    if (K <= 0 || K > count) {
        printf("�����Kֵ���Ϸ�");
        return 1;
    }
    char *elementValue = getElementByReverseOrder(&queue, K, count);
    if (elementValue != NULL) {
        printf("������%d���ַ���Ϊ:%s\n", K,elementValue);
    } else {
        printf("error occurs");
    }
    ClearQueue(&queue);
    return 0;
}
