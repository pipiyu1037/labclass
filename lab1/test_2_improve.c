#include<stdio.h>
int main()
{
    int m,n,k,p,i,d;
    printf("input m,n\n");
    scanf("%d%d",&m,&n);
    getchar();
    if(m<n)
    {
        n=m^n;
        m=n^m;
        n=m^n;
    } 
    k=0;
    while(m&1==0 && n&1==0)
    {
        m/=2;
        n/=2;
        k++;
    }
    for(p=1,i=0;i<k;i++) p=p<<1;
    while ((d=m-n)!=n)
    {
        if(d>n)m=d;
        else
        {
            m=n,n=d;
        }
    }
    d*=p;
    printf("the greatest common divisor:%d",d);
    getchar();
    return 0;
}