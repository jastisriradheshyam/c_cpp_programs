/*
IIT 2006 question
uncomment the below commented coded lines to see whats going on.
*/
#include<stdio.h>
void swap(int *x,int *y)
{
    static int *temp;
    temp = x;
    //printf(" x = %d ,y = %d\n",*x,*y);
    x = y;
    //printf(" x' = %d ,y' = %d\n",*x,*y);
    y = temp;
    //printf(" x'' = %d ,y'' = %d\n",*x,*y);
}
void printab()
{
    static int i,a = -3,b = -6;
    i = 0;
    while(i<=4)
    {
        if((i++)%2 == 1) continue;
       // printf(" a' = %d, b' = %d \n", a,b);
        a = a + i;
        b = b + i;
        //printf(" a'' = %d, b'' = %d, i = %d \n", a,b,i);
    }
    swap(&a,&b);
    printf("a = %d, b = %d\n", a, b);
}
int main()
{
    printab();
    printab();
    return 0;
}