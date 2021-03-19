#include<stdio.h>
long get_sum(long n);
void get_equ(long n);
int main()
{
    long n;
    printf("Input a number:");
    while (scanf("%ld",&n)!=EOF)
    {
        if(get_sum(n)==n)
        {
            printf("%ld is a perfect number.\n",n);
            printf("%ld=1",n);
            get_equ(n);
            printf("\n"); 
        }
        else
            printf("%ld isn't a perfect number.\n",n);
    }
    return 0;
}

long get_sum(long n)
{
    long i,j,sum;
    sum=0;
    for ( i = 1; i < n; i++)
    {
        for ( j = 1; j < n; j++)
        {
            if(n==j*i)
                sum+=i;            
        }
    }
    return sum+1;
}

void get_equ(long n)
{
    long i,j,sum;
    sum=0;
    for ( i = 1; i < n; i++)
    {
        for ( j = 1; j < n; j++)
        {
            if(n==j*i)
            {
                sum+=i;        
                printf("+%ld",i);
            }
        }
    }
}