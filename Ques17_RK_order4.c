//Runge-kutta's method

/*
PS E:\vsc2.0> cd "e:\vsc2.0\GitHub\CBNST\CBNST_LAB_WORK\" ; if ($?) { gcc Ques17.c -o Ques17 } ; if ($?) { .\Ques17 }
Enter value of x0, y0, h and xn:0 1 0.2 0.2

In 0 iteration, x0= 0.000000 y0= 1.000000, k1= 0.200000, k2= 0.240000, k3= 0.244000, k4= 0.248800

y at 0.200000 is: 1.236133
*/

float f(float x,float y)
{
    return x+y;
}
#include <stdio.h>
int main()
{
    float x0,y0,xn,h;
    printf("Enter value of x0, y0, xn and h:");
    scanf("%f %f %f %f",&x0,&y0,&xn,&h);
    float n=(xn-x0)/h;
    float k1,k2,k3,k4;
    int i;
    for(i=0;i<n;i++)
    {
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2,y0+k1/2);
        k3=h*f(x0+h/2,y0+k2/2);
        k4=h*f(x0,y0+k3);
        printf("\nIn %d iteration, x0= %f y0= %f, k1= %f, k2= %f, k3= %f, k4= %f",i,x0,y0,k1,k2,k3,k4);
        y0= y0+(k1+2*k2+2*k3+k4)/6;
        x0=x0+h;
    }
    printf("\n\ny at %f is: %f",x0,y0);
    return 0;
}