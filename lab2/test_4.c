 #include<stdio.h>
 int main()
 {
     unsigned long num;
     printf("input enter");
     getchar();
     for ( num=100; num<=999; num++)
     {
         if (num==(num*num)%1000)
             printf("%lu\n",num);
     }
     getchar();
     return 0;
 }