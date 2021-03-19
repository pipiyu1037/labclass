#include<stdio.h>
int main()
{
    unsigned char num[5];  /*待加密数*/
    unsigned char n0,n1,n2,n3,n4,n5,n6,mask;  /*逻辑尺*/
    unsigned char i,t,j;  /*中间量*/
    printf("Input:");
    scanf("%s",&num);
    getchar();
    for (i = 0;i<=5; i++)
    {
        n0=0x1;
        n1=0x2;
        n2=0x4;
        n3=0x8;
        n4=0x10;
        n5=0x20;
        n6=0xc0;
        num[i]=(n0&num[i])<<1|(n1&num[i])>>1|(n2&num[i])<<1|(n3&num[i])>>1|(n4&num[i])<<1|(n5&num[i])>>1|(n6&num[i]);
        j=(num[i]&n6)>>6;
        mask=0x3f;
        t=((mask&num[i])<<j|(mask&num[i])>>6-j)&mask;
        num[i]=j<<6 |t;
    }
    printf("Output:%s",num);
    getchar();
    return 0;
}