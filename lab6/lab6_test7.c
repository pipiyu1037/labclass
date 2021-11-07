#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define N 20
#define MAX 80
char *goAhead(char *a,int n); 
int main()
{
    char *a[N];
    int i=0,j=0,flag;
    do{
        flag=0;
        a[i]=malloc(MAX);
        fgets(a[i],MAX,stdin);
        for(j=0;flag==0;j++)
        {
            if(*(a[i]+j)!=' '&&*(a[i]+j)!='\t')
                flag=1;
        }
        a[i]=goAhead(a[i],j-1);
        i++;
    }while(*(a[i-1])!='\n'&&i<N);
    for(int m=0;m<=i-2;m++)
    {
        fputs(a[m],stdout);
    }
    return 0;
}

char*goAhead(char*a,int n)
{
    int i=0;
    while(*(a+n+i)!='\0')
    {
       *(a+i)=*(a+n+i);
       i++;
    }
    *(a+i)=*(a+n+i);
    return a;
}
