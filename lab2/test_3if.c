#include<stdio.h>
#define BASE1 1000
#define BASE2 2000
#define BASE3 3000
#define BASE4 4000
#define BASE5 5000
#define S1 50
#define S2 150
#define S3 300
#define S4 500
int main()
{
    int salary;
    int rate;
    
    printf("input your salary:");
    while (scanf("%d",&salary)!=!EOF)
    {
        rate=salary/1000;
        if (rate==0)
            printf("0");
        else if (rate==1)
            printf("%.2f\n",(salary-BASE1)*0.05);
        else if (rate==2)
            printf("%.2f\n",(salary-BASE2)*0.10+S1);
        else if (rate==3)
            printf("%.2f\n",(salary-BASE3)*0.15+S2);
        else if (rate==4)
            printf("%.2f\n",(salary-BASE4)*0.20+S3);
        else
            printf("%.2f\n",(salary-BASE5)*0.25+S4);
    }
    return 0;
}