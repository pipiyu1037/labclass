#include<stdio.h>
int main()
{
    int i,x,k,flag;
    printf("judge a composite,Ctrl+z to quit\n");
    while (scanf("%d",&x)!=EOF)
    {
        i=2;
        flag=0;
        k=x>>1;
        do
        {
            if (!(x%i))
            {
                flag=1;
            }
            i++;
        }while (i<=k&&flag==0);
        if (flag==1)
            printf("%d is composite number\n",x);
        else
            printf("%d isn't composite number\n",x);
    }
    return 0;
}