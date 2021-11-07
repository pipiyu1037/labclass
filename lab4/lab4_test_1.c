#include<stdio.h>
#define SUM(a,b) (a+b)
#define DIF(a,b) (a-b)
#define SWAP(a,b,temp)  temp=b,b=a,a=temp
int main() 
{
    int a,b,temp;
    printf("Input two integers a, b:");
    scanf("%d%d", &a,&b);
    printf("SUM=%d\nthe difference between square of a and square of b is:%d",SUM(a,b), SUM(a,b)*DIF(a,b));
    SWAP(a,b,temp);
    printf("\nNow a=%d,b=%d\n",a,b);
    return 0;
}
