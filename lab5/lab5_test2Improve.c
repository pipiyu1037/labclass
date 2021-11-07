#include<stdio.h>
#define M 10
#define N 3
int main(void)
{
    int a[M], b[M],tag[M];	
    int i, j, k,count=0;
    for(i = 0; i < M; i++)			
    a[i] = i + 1;
    for(i = M, j = 0; i > 1;)
    {
        for(k = 1; k <= N; k++)			/* 1至N报数 */
        {
            if(!(a[j])) 
            {
                k--;
                j++;
                continue;
            }
            if(++j > M - 1) j = 0;/* 最后一个人报数后第一个人接着报，形成一个圈 */
        }
     	b[count] = j?a[j-1]:a[M-1];	/* 将报数为N的人的编号存入数组b */
        count++;
        if(j)
            a[j-1]=0;
        else
            a[M-1]=0;
        if(count==M-1)
            break;
    }
    for(i = 0;i < M-1; i++)		/* 按次序输出出圈人的编号 */
    printf("%6d", b[i]);
    for(i=0;i<M;i++)
        if(a[i])
            printf("%6d\n", a[i]);			/* 输出圈中最后一个人的编号 */
    return 0;
}	
