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
#define S5 750
int main()
{   
    int salary;
    printf("input your salary:");
    while (scanf("%d",&salary)!=EOF)
    {
        switch ((int)salary/1000)
        {
        case 0:printf("0\n");
            break;
        case 1:printf("%.2f\n",(salary-BASE1)*0.05);
            break;
        case 2:printf("%.2f\n",(salary-BASE2)*0.10+S1);
            break;
        case 3:printf("%.2f\n",(salary-BASE3)*0.15+S2);
            break;
        case 4:printf("%.2f\n",(salary-BASE3)*0.20+S3);
            break;
        default:printf("%.2f\n",(salary-BASE4)*0.25+S4);
            break;
        }
    }
    return 0;
}