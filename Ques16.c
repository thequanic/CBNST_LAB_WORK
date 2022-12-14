//eulers method

#include <stdio.h>
double fun(double x,double y)
{
    return x+y;
}
int main()
{
    double x0,y0,x,h;
    printf("Enter value of x0:");
    scanf("%lf",&x0);
    printf("Enter value of y0:");
    scanf("%lf",&y0);
    printf("Enter x:");
    scanf("%lf",&x);
    printf("Enter value of h:");
    scanf("%lf",&h);
    int n=(x-x0)/h;
    double y;
    int i=0;
    printf("\n\nx      \ty      ");
    for(i=0;i<=n;i++)
    {
        printf("\n%7lf\t%7lf",x0,y0);
        y=y0+h*fun(x0,y0);
        y0=y;
        x0=x0+h;
    }
    printf("\n\ny at %7lf: %7lf",x,y0);
    return 0;
}