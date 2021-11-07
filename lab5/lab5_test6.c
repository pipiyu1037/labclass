#include<stdio.h>
#include<string.h>
char *strnins(char s[],char t[],int n);
int main()
{
    char a[10]="++-+";
    char b[10]="-";
    char *s;
    s=strnins(a,b,1);
    printf("%s",s);
}

char *strnins(char s[],char t[],int n)
{
    char* rel=s;
    int i=n;
    int j=0;
    char temp[30];
    while(s[i]!='\0')
    {
        temp[j++]=s[i++];
    }
    temp[j]='\0';
    j=0,i=n;
    while(t[j]!='\0')
    {
        s[i++]=t[j++];
    }
    j=0;
    while(temp[j]!='\0')
        s[i++]=temp[j++];
    s[i]='\0';
    return  rel;
    
}