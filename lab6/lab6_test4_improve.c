#include <stdio.h>
char *strcpy(char *,const char *);
void main(void)
{
    char a[40],b[60]="there is a boat on the lake.";
    printf("%s\n",strcpy(a,b));

}

char * strcpy(char *s, const char *t)
{
    char *temp;
    temp=s;
	while((*t)!='\0')
    *(s++)=*(t++);
	*s='\0';
	return temp;
}