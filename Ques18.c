//curve fitting
/*
PS E:\vsc2.0> cd "e:\vsc2.0\GitHub\CBNST\CBNST_LAB_WORK\" ; if ($?) { gcc Ques18.c -o Ques18 } ; if ($?) { .\Ques18 }
Enter number of provided x,y values:6
Enter values of x and y for 6 times:
Enter x:43
Enter y:99
Enter x:21
Enter y:65
Enter x:25
Enter y:79
Enter x:42
Enter y:75
Enter x:57
Enter y:87
Enter x:59
Enter y:81

Table is:

x               y               xy              x^2
43.000000       99.000000       4257.000000     1849.000000
21.000000       65.000000       1365.000000     441.000000
25.000000       79.000000       1975.000000     625.000000
42.000000       75.000000       3150.000000     1764.000000
57.000000       87.000000       4959.000000     3249.000000
59.000000       81.000000       4779.000000     3481.000000

Sigma x : 247.000000
Sigma y: 486.000000
Sigma x*y: 20485.000000
Sigma x square: 11409.000000
Cofficients are: a=65.141571 b=0.385225
Equation of curve is: y = 65.141571 + 0.385225 * x
Enter value of x for which y need to be calculated:23
y for 23.000000 is 74.001746
*/
#include <stdio.h>
float a(float sum_x,float sum_y,float sum_xy,float sum_x2,int n)
{
    return (sum_x2*sum_y-sum_xy*sum_x)/(n*sum_x2-sum_x*sum_x);
}
float b(float sum_x,float sum_y,float sum_xy,float sum_x2,int n)
{
    return (n*sum_xy-sum_y*sum_x)/(n*sum_x2-sum_x*sum_x);
}
float cal_y(float x, float a, float b)
{
    return a+b*x;
}
int main()
{
    printf("Enter number of provided x,y values:");
    int n;
    scanf("%d",&n);
    int i,j;
    float x[n],y[n],xy[n],x2[n];
    printf("Enter values of x and y for %d times:\n",n);
    for(i=0;i<n;i++)
    {
        printf("Enter x:");
        scanf("%f",&x[i]);
        printf("Enter y:");
        scanf("%f",&y[i]);
        xy[i]=x[i]*y[i];
        x2[i]=x[i]*x[i];
    }
    float sum_x=0,sum_y=0,sum_xy=0,sum_x2=0;
    printf("\nTable is:\n");
    printf("\nx        \ty        \txy        \tx^2      ");
    for(i=0;i<n;i++)
    {
        printf("\n%9f\t%9f\t%9f\t%9f",x[i],y[i],xy[i],x2[i]);
        sum_x+=x[i];
        sum_y+=y[i];
        sum_xy+=xy[i];
        sum_x2+=x2[i];
    }
    printf("\n\nSigma x : %f",sum_x);
    printf("\nSigma y: %f",sum_y);
    printf("\nSigma x*y: %f",sum_xy);
    printf("\nSigma x square: %f",sum_x2);
    float _a=a(sum_x,sum_y,sum_xy,sum_x2,n);
    float _b=b(sum_x,sum_y,sum_xy,sum_x2,n);
    printf("\nCofficients are: a=%f b=%f",_a,_b);
    printf("\nEquation of curve is: y = %f + %f * x",_a,_b);
    printf("\nEnter value of x for which y need to be calculated:");
    float X;
    scanf("%f",&X);
    printf("y for %f is %f",X,cal_y(X,_a,_b));
    return 0;
}