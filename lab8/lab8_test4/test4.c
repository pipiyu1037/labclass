#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    float a[10];
    int i=0;
    char ptr[40];
	FILE *fp;
    if((fp=fopen("C:\\Users\\Pipiyu\\Desktop\\program\\lab8\\lab8_test4\\.float.dat","r+"))==NULL){        
		printf("Can't open file!\n");
		exit(-1);
	}
    while(i<10) scanf("%f",&a[i++]);
    for(i=0;i<10;i++){
        fprintf(fp,"%f",a[i]);
        printf("%f ",a[i]);
    }
    fclose(fp);
    if((fp=fopen("C:\\Users\\Pipiyu\\Desktop\\program\\lab8\\lab8_test4\\.float.dat","rb"))==NULL){        
		printf("2.Can't open file!\n");
		exit(-1);
	}
    printf("\n");
    for(i=0;i<40;i++){
        fread(&ptr[i],1,1,fp);
        printf("%2x ",ptr[i]);
        if (i%4==3) printf("\n");
    }
    return 0;
}