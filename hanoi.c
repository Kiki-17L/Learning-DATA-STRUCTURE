#include<stdio.h>
void move(char A, char B){

    printf("%c -> %c\n",A,B);


}
void Hanoi(int n,char A, char B,char C)
{
    if (n==1)
    {
        move(A,C);/* code */
    }
    else
    {
        Hanoi(n-1,A,C,B);
        move(A,C);
        Hanoi(n-1,B,A,C);
    }
    

}
int main(int argc, char const *argv[])
{
    Hanoi(8,'A','B','C');

    return 0;
}
