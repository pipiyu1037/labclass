#include<stdio.h>
int main()
{
    unsigned short int x,m,n;
    unsigned short int i,j,t;    /*逻辑尺 i表示第m+n位，l表示第i位的left，r表示第i位的right*/
    printf("input:x,m,n\n");
    scanf("%hx %hu %hu",&x,&m,&n);
    getchar();
    if (m>=0&&m<=15&&n>=1&&n<=16-m)//判断m，n的范围
    {
        j=0x1<<m;
        for(i=1;i<=n-1;i++)
        {
            j=j|(j<<1);
        }
        t=x&j;
        x=x&(~j);
        j=j<<16-m-n;
        x=(x&~j)|(t<<16-m-n);
        printf("output:%hx\n",x);
    }
    else
    {
        printf("error");/*根据m，n的范围报错*/
    }
    getchar();
    return 0;
}