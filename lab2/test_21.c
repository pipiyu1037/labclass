#include<stdio.h>
int main()
{
    int i,x,k,flag;
    printf("judge a composite,Ctrl+z to quit\n");
    while (scanf("%d",&x)!=EOF)
    {
        for ( i=2,flag=0,k=x>>1;i<=k&&flag==0;i++){
            if (!(x%i))
                flag=1;
        }
            if (flag==1)
                printf("%d is a composite\n",x);
            else
                printf("%d isn't acomposite\n",x);
    }
    return 0;
}