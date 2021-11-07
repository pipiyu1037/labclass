#include<stdio.h>
int main()
{
    int i,j,line,num;
    scanf("%d",&line);
    getchar();
    for (i = 0; i <= line; i++)
    {
        for ( j = 1; j <=(line-i)*2 ; j++)
            printf(" ");
        for ( num=1,j=1;j<=i+1; j++)
        {
            printf("1");
            for ( num=1,j=1;j<=i+1; j++)
            {
                if((i-j+1)!=0){
                num=num*(i-j+1)/j;
                printf("%4d",num);
                }
            }
            printf("\n");
        }
    }
    getchar();
    return 0;
 }