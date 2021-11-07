#include<stdio.h>
void output(char a[],int n);
int main()
{
    unsigned int num;
    char a[33];
    while (scanf("%u",&num)!=EOF)
    {
        int r,i;
        for(i=0;num>=2;i++)
        {
            r=num%2;
            a[i]=(r==0?'0':'1');
            num/=2;
        }
        if(num==1)
            a[i]='1';
        else
            i--;
        output(a,i);
        printf("\n");
    }
    return 0;
}
void output(char a[],int n)
{
    int i;
    for(i=n;i>=0;i--)
        putchar(a[i]);
}