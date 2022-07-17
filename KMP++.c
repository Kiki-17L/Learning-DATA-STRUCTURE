//现撸kmp++


#include<stdio.h>
#include<string.h>
#define MAXSIZE 100


void get_nextval(char * T,int * nextval){

    int k=-1,j=0;
    int lenT=strlen(T);
    nextval[0]=-1;
    while (j< lenT-1)
    {
        if (k==-1 || T[k]==T[j])
        {
            k++;
            j++;
            if (T[k]!=T[j])//避免无效的比较T[j]==T[k]
            {
                nextval[j]=k;
            }
            else
            {
                nextval[j]=nextval[k];
            }
        }else
        {
            k=nextval[k];//k的回溯
        }
        
     }
    
}

int KMPmatch(char * S,char * T){
    int i=0,j=0;
    int lenS=strlen(S),lenT=strlen(T);
    int nextval[MAXSIZE];
    get_nextval(T,nextval);
    while (i< lenS && j< lenT)
    {
        if ( j==-1   ||  S[i]==T[j])
        {
            i++;
            j++;
        }
        else
        {
            j=nextval[j];//指导j的回溯
        }
    }
    if (j==lenT)
    {
        return i-lenT;
    }
    else
    {
        return -1;
    }
    
    
    



}


int main(int argc, char const *argv[])
{
    char S[MAXSIZE],T[MAXSIZE];
    printf("请输入主串:");
    gets(S);
    printf("请输入子串:");
    gets(T);
    printf("子串的位置位于:%d\n",KMPmatch(S,T));
    return 0;
}

