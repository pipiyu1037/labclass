#include<stdio.h>
int main()
{
    char ch;
    while ((ch=getchar()) !=EOF) 
    {
        putchar((ch>'a'&&ch<='z')?ch:ch+'a'-'A');
        printf("\n");
    }
}