#include<stdio.h>
#include<stdlib.h>
void output(int*a,int i,int j);
int main()
{
    int i,j,count1=0,count2=0;
    scanf("%d%d",&i,&j);
    int *num;
    num=malloc(i*j*sizeof(int));
    int *temp=num;
    while(count1<i)
    {
        while(count2<j)
        {
            scanf("%d",num);
            num++;
            count2++;
        }
        count2=0;
        count1++;
    }
    printf("...\n");
    output(temp,i-1,j-1);
    return 0;
}

void output(int *a,int i,int j)
{
    int b,t;
    for(t=j;t>=0;t--)
    {
        for(b=0;b<=i;b++)
        {
            printf("%4d",*(a+t+b*(j+1)));
        }
        printf("\n");
    }
}