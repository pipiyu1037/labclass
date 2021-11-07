#include<stdio.h>
#include<stdlib.h>
char *strcopy(char *, const char *);
int main(void)
{
	char *s1, *s2, *s3;
	s1=malloc(20);
	s2=malloc(20);
	s3=malloc(20);
	printf("Input a string:\n");
	fgets(s2,19,stdin);
	strcopy(s1, s2);
	printf("%s",s1);
	printf("Input a string again:\n");
	fgets(s2,19,stdin);
	s3 = strcopy(s1, s2);
	printf("%s", s3);
	free(s1);
	free(s2);
	free(s3);
	return 0;
}

/*将字符串s复制给字符串t，并且返回串t的首地址*/
char * strcopy(char *t, const char *s)
{
    char *temp;
    temp=t;
	while((*s)!='\0')
    *(t++)=*(s++);
	*t='\0';
	return temp;
}

