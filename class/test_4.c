#include<stdio.h>
int main()
{
    unsigned short int x,m,n;
    unsigned short int i,l,r;    /*逻辑尺 i表示第m+n位，l表示第i位的left，r表示第i位的right*/
    printf("input:x,m,n\n");
    scanf("%hx %hu %hu",&x,&m,&n);
    getchar();
    i=0x0001;
    l=0xffff;
    r=0xffff;
    i<<=m+n;          /*从m位开始向左n位*/
    i&=x;             /*取出第m+n位*/
    i<<=15-m-n;       /*向左靠齐*/             
    l<<=m+n+1;
    l&=x;             /*取出第m+n位左边的所有位*/
    l>>=1;            /*将左边的位全向右移一位*/
    r>>=15-(m+n-1);   /*取出第m+n位右边的所有位*/
    x=((i&x)|l|(r&x));
    printf("output:%#hx",x);
    getchar();
    return 0;
}