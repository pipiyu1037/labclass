# include<stdio.h>
# include<string.h>
int main (void)
{
	char* (*p[]) (char *,const char*)={
        strcpy,strcat,strtok
    };
    char a[80], b[80], *result;
    int choice;
    while(1)
    {
	    do{
		    printf("\t\t1 copy string.\n");
		    printf("\t\t2 connect string.\n");
		    printf("\t\t3 parse string.\n");
            printf("\t\t4 exit.\n");
			printf("\t\tinput a number (1-4) please.\n");
			scanf("%d", &choice);
        }while(choice<1 || choice>4);
        getchar();
        if(choice==4) return 0;
        printf("input the first string please!\n");
        gets(a);
        printf("input the second string please!\n");
        gets(b);
        result = p[choice-1](a, b);
        printf("the result is %s\n", result);
    }
	return 0;
}
