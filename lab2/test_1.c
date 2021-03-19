#include<stdio.h>
int main()
{
    int i,x,k,flag;
    printf("judge a composite,Ctrl+z to quit\n");
    while (scanf("%d",&x)!=EOF)
    {
        for(i=2,flag=0,k=x>>1;i<=k;i++)
            if (!(x%i)){
                flag=1;
                break;
            }
        if (flag==1)
            printf("%d is composite number\n",x);
        else 
            printf("%d isn't composite number\n",x);
    }
    return 0;
}