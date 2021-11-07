#include<stdio.h>
int main()
{
    int x,i,j,p,k,m,n,flag,num,y,z;
    num=0;
    flag=0;
    for (x=400;x<=999;x++)
    {
        for (i=2,k=x>>1;i<=k&&flag==0;i++)
            if(!(x%i))
                flag=1;
        for (j=2,y=x/10,m=y>>1;j<=m&&flag==1;j++)
            if(!(y%j))
                flag=2;
        for (p=2,z=x/100,n=z>>1;p<=n&&flag==2;p++)
            if (!(z%p))
                flag=3;                                                    
        if(flag==3){
            num++;
        }
        flag=0;
    }
    printf("%d",num);
    getchar();
    return 0;
}