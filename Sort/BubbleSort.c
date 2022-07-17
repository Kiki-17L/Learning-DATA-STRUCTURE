#include<stdio.h>
#define MAX 10000
static int compare=0,change=0;

void BubbleSort(int * a){
    int temp;
    for (int i = 0; i < MAX-1; i++)
    {
        int flag=0;
        for (int j = 0; j < MAX-1-i; j++)
        {
            if (a[j]>a[j+1])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
                change+=3;
                flag=1; 
            }
            compare++;
        }
        if (!flag)
        {
            return;
        }
    }
    
}


int main(int argc, char const *argv[])
{
    int array[MAX];
    for (int i = 0; i < MAX; i++)
    {
        array[i]=MAX-i-1;
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%2d",array[i]);
    }
    BubbleSort(array);
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%2d",array[i]);
    }
    printf("\n比较次数:%d\n交换次数:%d",compare, change);
    return 0;
}
