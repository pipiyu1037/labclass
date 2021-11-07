#include<stdio.h>
#include<math.h>
#define S(a,b,c) (a+b+c)/2
#define AREA(a,b,c,s) sqrt(s*(s-a)*(s-b)*(s-c))
int main(void)
{
    float a,b,c,s;
    printf("Input three lenth a,b,c:");
    scanf("%f%f%f",&a,&b,&c);
    s=S(a,b,c);
    printf("The area is %f",AREA(a,b,c,s));
    return 0;
}