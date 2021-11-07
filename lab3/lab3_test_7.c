#include<stdio.h>
long get_sum(int n,int k);
long get_power(int m, int k);
int main()
{
    int n,i,m,k;
    printf("Input k :\n");
    while (scanf("%d",&k)!=EOF)
    {
        n=1;
        for ( i = 1; i < k; i++)
            n=n*10;
        for ( m=n*10;  n< m; n++)
        {
            if(get_sum(n,k)==n)
                printf("%d is a self-power.\n",n);
        }
    }
    return 0;
}

long get_sum(int n,int k)
{
    int m,i;
    long sum,power;
    sum=0;
    for ( i = 1; i <= k; i++)
    {
        m=n%10;
        n=n/10;
        power=get_power(m,k);
        sum+=power;
    }
    return sum;
}

long get_power(int m,int k)
{
    int i;
    long power;
    power=1;
    for ( i = 1; i <= k; i++)
        power*=m;
    return power;
}