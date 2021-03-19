#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"form.h"
int main()
{
    List pNode,*plist=&pNode;
    printf("What are you going to do?(input 0 to quit)\n");
    printf("1)Input information of students.\n");
    printf("2)Show information of students.\n");
    printf("3)Change date.\n");
    printf("4)show the information of a student you point.\n");
    printf("5)Sort according to average(date).\n");
    printf("6)Sort according to average(node).\n");
    int choice;
    scanf("%d",&choice);
    while(getchar()!='\n') continue;
    while(choice)
    {
        if(choice==1) 
        {
            InputInformation(plist);
        }
        if(choice==2)
        {
            outputStudent(*plist);    
        }
        if(choice==3)
        {
            changeInformation(plist);  
        }
        if(choice==4)
        {
            outputoneStudent(plist);
        }
        if(choice==5)
        {
            sortBydate(plist);
        }
        if(choice==6)
        {
            sortBypoint(plist);
        }
        printf("Next!\n");
        scanf("%d",&choice);
        while(getchar()!='\n') continue;
    }
    printf("Ending!");
    return 0;
}
char * s_gets(char * st,int n)
{
    char * rel;
    int i=0;
    rel=fgets(st,n,stdin);
    if(rel)
    {
        while(st[i]!='\n'&&st[i]!='\0') i++;
        if(st[i]=='\n')
            st[i]='\0';
        else
            while(getchar()!='\n') continue;
    }
    return rel;
}
/*返回节点数量*/
int nodecounter(List * plist)
{
    unsigned int count = 0;
    Node * pnode=*plist;
    if(pnode) count++;
    while(pnode->next)
    {
        count++;
        pnode=pnode->next;
    }
    return count;
}
/*求学生的总成绩*/
int scoreTotal(Item * pstud)
{
    int total;
    total=(pstud->eng)+(pstud->math)+(pstud->physics)+(pstud->cprogram);
    return total;
}
/*求学生的平均成绩*/
float scoreAverage(Item * pstud)
{
    float average;
    average=(float)scoreTotal(pstud)/4.0;
    return average;
}
/*输入某个学生的信息*/
int getOnestudent(Item * pstud)
{
    puts("Input Number.");
    s_gets(pstud->number,SIZE);
    if((pstud->number)[0]=='\0')
        return 0;
    puts("Input name:");
    s_gets(pstud->name,SIZE);
    puts("Input English,math,physics and cprogramming score in roder:");
    scanf("%d %d %d %d",&(pstud->eng),&(pstud->math),&(pstud->physics),&(pstud->cprogram));
    while(getchar()!='\n') continue;
    (pstud->total)=scoreTotal(pstud);
    (pstud->average)=scoreAverage(pstud);
    return 1;
}
/*输入所有学生信息*/
void InputInformation(List * plist)
{
    Node *pnode;
    pnode=(Node*) malloc(sizeof(Node));
    *plist=pnode;
    while (getOnestudent(&(pnode->stu)))
    {
        pnode->next=(Node *) malloc(sizeof(Node));
        pnode=pnode->next;
    }
    pnode->next=NULL;
}
/*输出所有学生的信息*/
void outputStudent(List pNode)
{
    while((pNode->next)!=NULL)
    {
        printf("Number:");
        puts((pNode->stu).number);
        printf("Name:");
        puts((pNode->stu).name);
        printf("English score:");
        printf(" %d",(pNode->stu).eng);
        printf("\nMath score:");
        printf(" %d",(pNode->stu).math);
        printf("\nPhysics score:");
        printf(" %d",(pNode->stu).physics);
        printf("\nCprogramming score: %d",(pNode->stu).cprogram);
        printf("\ntotal score: %d",(pNode->stu).total);
        printf("\nAverage score: %.2f\n",(pNode->stu).average);
        printf("****************************\n");
        pNode=pNode->next;
    }
}
/*寻找指定学号学生的位置*/
int findStudent(List * plist,char* number)
{
    Node *pNode=*plist;
    int pos=0;
    while(pNode->next)
    {
        if(strcmp((pNode->stu).number,number)!=0)
        {
            pos++;
            pNode=pNode->next;
        }
        else return pos;
    }
    return -1;
}
/*输出指定学生信息*/
void outputoneStudent(List * plist)
{
    char *numberfind;
    numberfind=(char *)malloc(SIZE*sizeof(char));
    printf("Please input the number of student"
        " you are going to find:\n");
    s_gets(numberfind,SIZE);
    int pos=findStudent(plist,numberfind),i;
    Node *pNode=*plist;
    if(pos>=0)
    {
        for(i=0;i<pos;i++)
        {
            pNode=pNode->next;
        }
        printf("Number:");
        puts((pNode->stu).number);
        printf("Name:");
        puts((pNode->stu).name);
        printf("English score:");
        printf(" %d",(pNode->stu).eng);
        printf("\nMath score:");
        printf(" %d",(pNode->stu).math);
        printf("\nPhysics score:");
        printf(" %d",(pNode->stu).physics);
        printf("\nCprogramming score: %d",(pNode->stu).cprogram);
        printf("\ntotal score: %d",(pNode->stu).total);
        printf("\nAverage score: %.2f\n",(pNode->stu).average);
    }
    else
        printf("Can't find the number!");
}
/*更改学生信息*/
void changeInformation(List * plist)
{
    char *findnumber;
    findnumber=(char*)malloc(SIZE*sizeof(char));
    printf("Please input the number of student"
        " you are going to find:\n");
    s_gets(findnumber,SIZE);
    int pos=findStudent(plist,findnumber),i;
    Node *pNode=*plist;
    if(pos>=0)
    {
        for(i=0;i<pos;i++)
        {
            pNode=pNode->next;
        }
        printf("Whice item would you change?(input 0 to quit)\n");
        printf("1)Name           2)English score\n");
        printf("3)Math score     4)Physics score\n");
        printf("5)Cprogramming score\n");
        int choice;
        scanf("%d",&choice);
        while(getchar()!='\n') continue;
        while(choice)
        {
            if(choice==1) 
            {
                puts("\nInput name:");
                s_gets((pNode->stu).name,SIZE);
            }
            if(choice==2)
            {
                scanf("%d",&((pNode->stu).eng));
                while(getchar()!='\n') continue;
            }
            if(choice==3)
            {
                scanf("%d",&((pNode->stu).math));
                while(getchar()!='\n') continue;
            }
            if(choice==4)
            {
                scanf("%d",&((pNode->stu).physics));
                while(getchar()!='\n') continue;
            }
            if(choice==5)
            {
                scanf("%d",&((pNode->stu).cprogram));
                while(getchar()!='\n') continue;
            }
            ((pNode->stu).total)=scoreTotal(&(pNode->stu));
            ((pNode->stu).average)=scoreAverage(&(pNode->stu));
            printf("Next choice!(input 0 to quit!)\n");
            scanf("%d",&choice);
            while(getchar()!='\n') continue;
        }
    }
    else
        printf("Can't find the number!");
}
/*交换数据域内容*/
void swapdate(Node * pNode1,Node * pNode2)
{
    Item item=pNode1->stu;
    (pNode1->stu)=(pNode2->stu);
    (pNode2->stu)=item;
}
/*通过交换数据域排序*/
void sortBydate(List * plist)/*选择排序*/
{
    Node * pNode=*plist, * phead=*plist;
    Node * pmin;
    while(phead->next)
    {
        pmin=phead;
        while(pNode->next)
        {
            if((pNode->stu).average<(pmin->stu).average)
                pmin=pNode;
            pNode=pNode->next;
        }
        swapdate(pmin,phead);
        phead=phead->next;
    }
}
/*交换节点域*/
int swappoint(Node ** pNode1,Node * pNode2)
{
    Node * ptemp;
    ptemp=*pNode1;
    *pNode1=pNode2;
    pNode2=pNode2->next;
    ptemp->next=ptemp->next->next;
    (*pNode1)->next=ptemp;
    return 0;
}
/*通过交换节点域排序*/
void sortBypoint(List * plist)
{
    Node * pNode1=*plist, * pNode2=*plist, * pNode3=*plist;
    int i,j,len;
    len=nodecounter(plist);
    for(i=0;i<len-2;i++)
    {
        pNode2=pNode3;
        int flag=0;
        for(j=0;j<len-2;j++)
        {  
            
            if((pNode2->stu).average>(pNode2->next->stu).average)
            {
                swappoint(&pNode2,pNode2->next);
                if(flag==0)
                    *plist=pNode2;
                flag=1;
            }
        }
    }
    *plist=pNode3;
}