#include<stdio.h>
void task0(void)
{
    printf("task0 is called.\n");
}
void task1(void)
{
    printf("task1 is called.\n");
}
void task2(void)
{
    printf("task2 is called.\n");
}
void task3(void)
{
    printf("task3 is called.\n");
}
void task4(void)
{
    printf("task4 is called.\n");
}
void task5(void)
{
    printf("task5 is called.\n");
}
void task6(void)
{
    printf("task6 is called.\n");
}
void task7(void)
{
    printf("task7 is called.\n");
}

void execute(void (*fun[])(void),int n)
{
    for(int i=0;i<n;i++)
    {
        fun[i]();
    }
}
void scheduler(void)
{
    void (*fun[8])(void)={task0,task1,task2,task3,task4,task5,task6,task7};
    int count=0;
    char i;
    void (*home[20])(void);
    while(1)
    {
        while ((i=getchar())!='\n')
        {
            i=i-'0';
            home[count]=fun[i];
            count++;
        }
        execute(home,count);
        count=0;
    }
}
int main()
{
    scheduler();
    return 0;
}