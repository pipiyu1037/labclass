#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20
#define M 10
char * s_gets(char*st,int n)
{
    char*ret_val;
    int i=0;

    ret_val=fgets(st,n,stdin);
    if (ret_val)
    {
        while(st[i]!='\n'&&st[i]!='\0')
            i++;
        if(st[i]=='\n')
            st[i]='\0';
        else
            while(getchar()!='\n')
                continue;
    }
    return ret_val;
}
int main()
{
    char a[M+N+1],b[M+N+1],result[N+M+1];
    printf("Input a:");
    s_gets(a,M+N+1);
    printf("\nInput b:");
    s_gets(b,N+M+1);
    char *pPoia;
    char *pPoib;
    int lena=strlen(a);
    int lenb=strlen(b);
    pPoia=strchr(a,'.');
    pPoib=strchr(b,'.');
    int difa=pPoia-a;
    int difb=pPoib-b;
    int decdifa=lena-difa-1;
    int decdifb=lenb-difb-1;
    int flag;
    if(decdifa>decdifb)
    {
        int i=0;
        for(;i<decdifa-decdifb;i++)
            result[i]=a[lena-1-i];
        for(;i<decdifa;i++)
            result[i]=a[lena-1-i]+b[lenb-1-(i-decdifa+decdifb)]-'0';
        flag=i;
    }
    else{
        int i=0;
        for(;i<decdifb-decdifa;i++)
            result[i]=b[lenb-1-i];
        for(;i<decdifb;i++)
            result[i]=b[lenb-1-i]+a[lena-1-(i-decdifb+decdifa)]-'0';
        flag=i;
    }
    result[flag++]='.';
    if(difa>difb)
    {
        int j=0;
        for(;j<difb;j++)
            result[flag++]=a[difa-j-1]+b[difb-j-1]-'0';
        for(;j<difa;j++)
            result[flag++]=a[difa-j-1];
    }
    else{
        int j=0;
        for(;j<difa;j++)
            result[flag++]=b[difb-j-1]+a[difa-j-1]-'0';
        for(;j<difb;j++)
            result[flag++]=b[difb-j-1];
    }
    for(int i=0;i<flag-1;i++)
    {
        if(result[i]>'9')
        {
            result[i]-=10;
            if(result[i+1]=='.')
                result[i+2]++;
            else
                result[i+1]++;
        }
    }
    if(result[flag-1]>'9')
    {
        result[flag-1]-=10;
        result[flag]='1';
        result[flag+1]='\0';
        for(;flag>=0;flag--)
            printf("%c",result[flag]);
    }
    else
    {
        result[flag]='\0';
        for(;flag>=1;flag--)
            printf("%c",result[flag-1]);
    }
    return 0;
}