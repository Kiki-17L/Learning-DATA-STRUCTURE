#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 10


int Compare=0,Change=0;

void InsertionSort(int *a){

    int temp,i,j;
    for ( i = 1; i < MAXSIZE; i++)
    {
        Compare++;
        if (a[i]<a[i-1])
        {
            temp=a[i];
            for ( j = i-1; j>=0 && a[j]>temp; j--,Compare++)
            {
                a[j+1]=a[j];
                Change+=3;
            }
            a[j+1]=temp;
            Change+=3;
        }
        
    }
    




}

int main(int argc, char const *argv[])
{
    int array[MAXSIZE];
    srand(time(NULL));
    for (size_t i = 0; i < MAXSIZE; i++)
    {
        array[i]=MAXSIZE-1-i;
    }
    for (size_t i = 0; i < MAXSIZE; i++)
    {
        printf("%2d",array[i]);
    }
    printf("\n");
    InsertionSort(array);
    for (size_t i = 0; i < MAXSIZE; i++)
    {
        printf("%2d",array[i]);
    }
    printf("\n交换次数:%d\n比较次数:%d",Change,Compare);
    
    return 0;
}
