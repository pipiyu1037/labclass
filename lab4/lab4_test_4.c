#include<stdio.h>
#define CHANGE 1
int main(void)
{
    char ch;
    printf("Please Input:\n");
    while ((ch=getchar())!=EOF)
    {
        #if CHANGE==1
            if (ch>='a'&&ch<='z')
            {
                ch=ch-'a'+'A';
            }
            else if (ch>='A'&&ch<='Z')
            {
                ch=ch-'A'+'a';
            }
            printf("%c",ch);
        #else
            printf("%c",ch);
        #endif

    }
    return 0;
}