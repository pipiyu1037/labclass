#include<stdio.h>
int main(int argc,char *argv[])
{
    int count;
    for(count=1;count<argc;count++)
        printf("%s\n",argv[count]);
    printf("%s\n%s\n%s","arg1","arg2","arg3");
    return 0;
}