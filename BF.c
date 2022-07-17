 #include<stdio.h>
#include<string.h>
#define MAXSIZE 100


int BF(char *s,char *t)
{
    int i ,j,start;
    start=i=j=0;
    while (s[i]!='\0' && t[j]!='\0')
    {
        if (s[i]==t[j])
        {
            i++;
            j++;
        }
        else
        {
            i=++start;
            j=0;
        }
        
    }
    if (t[j]=='\0')
    {
        return start;
    }
    else return -1;
    
    
    
    


}

int main(int argc, char const *argv[])
{
    char s[MAXSIZE],t[MAXSIZE];
    printf("请输入主串:");
    gets(s);
    printf("请输入模式串:");
    gets(t);
    printf("坐标位于:%d",BF(s,t));
    return 0;
}
