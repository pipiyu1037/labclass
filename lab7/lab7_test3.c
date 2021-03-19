#include<stdio.h>
struct bits {
    unsigned int bit0 : 1;
    unsigned int bit1 : 1;
    unsigned int bit2 : 1;
    unsigned int bit3 : 1;
    unsigned int bit4 : 1;
    unsigned int bit5 : 1;
    unsigned int bit6 : 1;
    unsigned int bit7 : 1;
};
union byte
{
    char ch;
    struct bits b;
};

void f0(struct bits b)
{
	printf("the function %d is called!\n"
        "The bit is : %d\n",0,b.bit0);
} 
void f1(struct bits b)
{
	printf("the function %d is called!\n"
        "The bit is : %d\n",1,b.bit1);
} 
void f2(struct bits b)
{
	printf("the function %d is called!\n"
        "The bit is : %d\n",2,b.bit2);
} 
void f3(struct bits b)
{
	printf("the function %d is called!\n"
        "The bit is : %d\n",3,b.bit3);
} 
void f4(struct bits b)
{
	printf("the function %d is called!\n"
        "The bit is : %d\n",4,b.bit4);
} 
void f5(struct bits b)
{
	printf("the function %d is called!\n"
        "The bit is : %d\n",5,b.bit5);
} 
void f6(struct bits b)
{
	printf("the function %d is called!\n"
        "The bit is : %d\n",6,b.bit6);
} 
void f7(struct bits b)
{
	printf("the function %d is called!\n"
        "The bit is : %d\n",7,b.bit7);
} 
int main()
{
    void (*pfun[])(struct bits b)={
        f0,f1,f2,f3,f4,f5,f6,f7
    };
    struct bits b;
    union byte by;
    scanf("%d",&by);
    if(by.b.bit0) pfun[0](by.b);
    if(by.b.bit1) pfun[1](by.b);
    if(by.b.bit2) pfun[2](by.b);
    if(by.b.bit3) pfun[3](by.b);
    if(by.b.bit4) pfun[4](by.b);
    if(by.b.bit5) pfun[5](by.b);
    if(by.b.bit6) pfun[6](by.b);
    if(by.b.bit7) pfun[7](by.b);
    return 0;
}