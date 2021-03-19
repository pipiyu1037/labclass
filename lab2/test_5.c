#include<stdio.h>
#include<stdbool.h>
#define STOP '|'
int main()
{
    char c;
    bool space=0;
    printf("enter(| to terminate)");
    while ((c=getchar())!=STOP)
    {   
        if (space==0&&c==' ')
        {
            putchar(c);
            space=1;
        }
        else if (space=1&&c==' ')
        {
            space=1;
        }
        else if(c!=' ')
        {
            putchar(c);
            space=0;
        }
    }
    getchar();
    return 0;
}