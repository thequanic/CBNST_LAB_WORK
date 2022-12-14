//Simpson's 3/8

#include <stdio.h>
#include <math.h>
double fun(double x)
{
    return log(x);
}
int main()
{
    double x0,xn,h;
    printf("Enter value of x0:");
    scanf("%lf",&x0);
    printf("Enter value of xn:");
    scanf("%lf",&xn);
    printf("Enter value of h:");
    scanf("%lf",&h);
    int n=(xn-x0)/h;
    double sum=0;
    printf("\n\nx       \ty");
    int i=0;
    for(i=0;i<=n;i++)
    {
        printf("\n%7lf\t%7lf",x0+h*i,fun(x0+h*i));
        if(i==0||i==n)
        {
            sum+=fun(x0+h*i);
        }
        else if(i%3==0)
        {
            sum+=2*fun(x0+h*i);
        }
        else
        {
            sum+=3*fun(x0+h*i);
        }
    }
    sum*=(3*h/8);
    printf("\n\nResult: %7lf",sum);
    return 0;
}