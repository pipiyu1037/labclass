#ifndef FORM_H
#define FORM_H
#include<stdbool.h>
#define SIZE 20
/*类型定义*/
struct student{
    char number[SIZE];
    char name[SIZE];
    int eng;
    int math;
    int physics;
    int cprogram;
    int total;
    float average;
};
typedef struct student Item;
typedef struct node{
    Item stu;
    struct node * next;
}Node;
typedef Node * List;
/*函数原型*/ 
char * s_gets(char * st,int n);
int nodecounter(List * plist);/*返回节点数量*/
void InputInformation(List * plist);/*输入学生信息*/
int getOnestudent(Item * pstud);/*输入某个学生的信息*/
void outputStudent(List pNode);/*输出所有学生的信息*/
int scoreTotal(Item * pstud);
float scoreAverage(Item * pstud);
void outputoneStudent(List * plist);/*输出指定学生的信息*/
int findStudent(List * plist,char* number);/*根据学号寻找学生的位置*/
void changeInformation(List * plist);/*更改学生信息*/
void swapdate(Node * pNode1,Node * pNode2);/*交换数据域内容*/
int swappoint(Node ** pNode1,Node * pNode2);/*交换节点域*/
void sortBydate(List * plist);/*通过交换数据域排序*/
void sortBypoint(List * plist);/*通过交换节点域排序*/
#endif