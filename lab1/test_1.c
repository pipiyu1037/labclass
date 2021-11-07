#include<stdio.h>
#define PI 3.14159
int main(void)
{
    int f,newint;
    unsigned short p,k;
    double c,r,s;

    /* task_1*/
    printf("Input Fahrenheit:");
    scanf("%d",&f);
    getchar();
    c=5./9*(f-32);
    printf("\n %d(F)=%.2f(C)\n\n",f,c);
    
    /*task_2*/
    printf("Input the radius r:");
    scanf("%lf",&r);
    s=PI*r*r;
    printf("\nThe acreage is %.2f\n\n",s);
    getchar();

    /*task_3*/
    k=0xa1b2,p=0x8432;
    newint=p&0xff00|k>>8;
    printf("newint=%#x\n\n",newint);

    getchar();
    return 0;
}