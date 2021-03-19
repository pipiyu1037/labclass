#include<stdio.h>
int main()
{
    unsigned long int ip,l1,l2,l3,l4,p1,p2,p3,p4;
    printf("Please iuput\n");
    while (scanf("%lu",&ip) !=EOF)
    {
        l1=0xff000000;
        l2=0x00ff0000;
        l3=0x0000ff00;
        l4=0x000000ff;
        p1=(ip&l1);
        p1>>=24;
        p2=(ip&l2);
        p2>>=16;
        p3=(ip&l3);
        p3>>=8;
        p4=(ip&l4);
        printf("address:%lu.%lu.%lu.%lu\n",p1,p2,p3,p4);
    }
    return 0;
}