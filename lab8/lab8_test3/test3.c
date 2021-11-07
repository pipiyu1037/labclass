#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    char ch,buffer1[20][255],buffer2[20][255],*ptr;
	FILE *fp;
    int i=0;
    if((fp=fopen(argv[1],"r+"))==NULL){        
		printf("Can't open %s file!\n",argv[1]);
		exit(-1);
	}
    while(fgets(buffer1[i],255,fp)) i++;
    for(int j=0;j<i;j++)
    {
        buffer2[j][0]='\0';
        while((ptr=strstr(buffer1[j],argv[2]))!=NULL)
        {
            *ptr='\0';
            strcat(buffer2[j],buffer1[j]);
            strcat(buffer2[j],argv[3]);
            strcpy(buffer1[j],ptr+strlen(argv[2]));
        }
        strcat(buffer2[j],buffer1[j]);
    }
    fclose(fp);
    fp=fopen(argv[1],"w");
    for (int j = 0; j <i; j++)
        fputs(buffer2[j],fp);
    return 0;
}