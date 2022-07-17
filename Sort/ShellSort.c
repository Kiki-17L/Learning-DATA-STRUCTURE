#include<stdio.h>


#define MAXSIZE 10000
static int Compare=0,Change=0;
//移位法
void ShellSort(int * a)
{
    int j;
    for (int gap = MAXSIZE/2; gap>=1; gap=gap/2)
    {
        for (int i = gap; i < MAXSIZE ; i++)
        {
            Compare++;
            if (a[i]<a[i-gap])
            {
                int temp=a[i];
                for ( j = i-gap; j>=0 && a[j]>temp; j-=gap)
                {
                    a[j+gap]=a[j];
                    Change+=3;
                }
                a[j+gap]=temp;
            }
        }
        
    }
   
}
//交换法
void Shell(int a[MAXSIZE])
{
	for (int gap = MAXSIZE/2; gap>=1; gap=gap/2)//设置增量
	{
		for (int i = 0; i < gap; i++) //遍历每个分组
        {
            for ( int j = i+gap; j < MAXSIZE; j+=gap)
            {
                Compare++;
                if (a[j]<a[j-gap])
                {
                    for (int k = j-gap; k>=0 && a[k]>a[k+gap]; k-=gap)
                    {
                        int temp = a[k];
                        a[k]=a[k+gap];
                        a[k+gap]=temp;
                        Change+=3;
                    }
                    
                }
                
            }
        }
        
		
	}
	
}

int main(int argc, char const *argv[])
{
    int array[MAXSIZE];
    for (size_t i = 0; i < MAXSIZE; i++)
    {
        array[i]=MAXSIZE-1-i;
    }
    for (size_t i = 0; i < 10; i++)
    {
        printf("%2d",array[i]);
    }
    printf("\n");
    Shell(array);
    for (size_t i = 0; i < 10; i++)
    {
        printf("%2d",array[i]);
    }
    printf("\n比较次数:%d\n交换次数:%d",Compare,Change);
    return 0;
}
