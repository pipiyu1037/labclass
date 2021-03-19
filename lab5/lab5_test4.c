#include<stdio.h>
#include<string.h>
#define LEN 20

int find(int n, int a[], int h)
{
	int i, l, mid;
	l = 0;
	while(l<=h)
	{
		mid=(l+h)/2;
		if(a[mid]==n)
		return mid;
		else if(a[mid]<n)
		h=mid-1;
		else 
		l=mid+1;
	}
	return -1;
}

void bubble_sort(char a[][LEN], int b[],int n)
{
    int i,j;
    int temp;
    char tag[LEN];
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(b[j]<b[j+1])
            {
                temp=b[j];
                strcpy(tag,a[j]);
                b[j]=b[j+1];
                strcpy(a[j],a[j+1]);
                b[j+1]=temp;
                strcpy(a[j+1],tag);
            }
        }
    }
}

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
    char a[LEN][LEN];
    int score[LEN];
    int i=0;
    int index,choice,flag;
    flag=0;
    printf("Choose one choice:\n");
    printf("1)Input the name and score of students.\n");
    printf("2)Sort the students according to scores.\n");
    printf("3)Fine a students by his scores.\n");
    printf("4)Out put the student's name and scores.\n");
    while(scanf("%d",&choice))
    {
        while(getchar()!='\n') continue;
        if(choice!=1&&choice!=2&&choice!=3&&choice!=4)
            printf("Enter error,please try again.\n");
        if(choice==1)
        {
            while(i<LEN)
            {
                printf("Iuput name:");
                s_gets(a[i],LEN);
                if(a[i][0]=='\0') break;
                printf("Input score:");
                scanf("%d",&score[i]);
                while(getchar()!='\n') continue;
                i++;
                flag=0;
            }
        }


        if(choice==2)
        {
            if(i!=0)
            {
                bubble_sort( a, score,i);
                flag=1;
            }
            else
                printf("Can't find data.\n");
            printf("\nnext!");
        }


        if(choice==3)
        {
            if(flag==1)
            {
                int n,pos,pos2;
                printf("Enter a score you want to find:(enter q to quit)");
                while(scanf("%d",&n))
                {
                    while(getchar()!='\n') continue;
                    pos=find(n,score,i-1);
                    if(pos>=0)
                        printf("%10s  %5d\n",a[pos],score[pos]);
                    else
                        printf("Not found!\n");
                    pos2=pos;
                    while(score[pos2+1]==score[pos2])
                    {
                        pos2++;
                        printf("%10s  %5d\n",a[pos2],score[pos2]);
                    }
                    pos2=pos;
                    while(score[pos2-1]==score[pos2])
                    {
                        pos2--;
                        printf("%10s  %5d\n",a[pos2],score[pos2]);
                    }
                }
                while(getchar()!='\n') continue;
                printf("next!\n");
            }
            else
                printf("You hadn't sort the data,"
                    "please enter 2 and try again.\n");
        }


        if(choice==4)
        {
            if(i!=0)
            {    
                for(index=0;index<i;index++)
                {
                    printf("%10s" "%5d\n",a[index],score[index]);
                }
            }
            else
                printf("Can't find data.\n");
        }
    }
    return 0;
}  