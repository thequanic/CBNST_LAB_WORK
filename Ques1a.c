/*
Program to find absolute, relative andpercentage error
*/
#include<stdio.h>
#include<math.h>

int main()
{
    float x,y;
    scanf("%f%f",&x,&y);

    printf("absolute error is: %f\n",x>y?(x-y):(y-x));
    printf("relative error is: %f\n",x>y?(x-y)/x:(y-x)/x);
    printf("percentage error is: %f\n",x>y?(x-y)*100/x:(y-x)*100/x);
}