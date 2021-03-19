#include<stdio.h>
int main()
{
    long num;
    char *str;
    str=&num;
    scanf("%ld",&num);
    char byte[4],sitnum[8];
    int i=0,mask=0xf;
    for (i = 0; i <4; i++)
    {
        byte[i]=*(str+i);
        sitnum[2*i]=mask&(byte[i]);
        sitnum[2*i+1]=mask&(byte[i]>>4);
    }
    for(i=7;i>=0;i--)
    {
        printf("%x",sitnum[i]);
    }
    return 0;
}