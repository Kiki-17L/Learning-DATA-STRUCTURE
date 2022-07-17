#include<stdio.h>
#include<stdlib.h>



#define max 10



void SelectSort(int * a){

    for (int i = 0; i < max-1; i++)
    {
        for (int j = i+1; j < max; j++)
        {
            if (a[i]<a[j])
            {
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
            
        }
        
    }
}


int main(int argc, char const *argv[])
{
    int array[max];
    for (int i = 0; i < max; i++)
    {
        array[i]=i;
    }
    SelectSort(array);
    for (int i = 0; i < max; i++)
    {
        printf("%2d",array[i]);
    }
    
    return 0;
}
