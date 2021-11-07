#include<stdio.h>
#include<stdbool.h>
void get_equation(int n);
bool judge_prinum(int n);
int main()
{
    int n;
    printf("Input a num.\n");
    while (scanf("%d",&n)!=EOF)
    {
        if(n>=4&&!(n%2))
            get_equation(n);
        else
            printf("Please input a num higher than 4 and even.\n");
    }
    return 0;
}

bool judge_prinum(int n)
{
    int i;
    bool flag;
    flag=1;
    for ( i = 2;i<=(n>>1); i++)
    {
        if(!(n%i))
        {
            flag=0;
            break;
        }
    }
    return flag;
}

void get_equation(int n)
{
    int i;
    for (i = 2; i<=n-2; i++)
    {
        if(judge_prinum(i)&&judge_prinum(n-i))
        {
            printf("%d=%d+%d\n",n,i,n-i);
            break;
        }
    }
}