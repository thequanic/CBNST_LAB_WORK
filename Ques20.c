//regression lines

/*

PS E:\vsc2.0> cd "e:\vsc2.0\GitHub\CBNST\CBNST_LAB_WORK\" ; if ($?) { gcc Ques20.c -o Ques20 } ; if ($?) { .\Ques20 }
Enter number of provided x,y values:5
Enter values of x and y for 5 times:
Enter x:2
Enter y:5
Enter x:4
Enter y:7
Enter x:6
Enter y:9
Enter x:8
Enter y:8
Enter x:10
Enter y:11

Table is:

x               y               X       Y       X^2             Y^2             X*Y      
 2.000000        5.000000       -4.000000       -3.000000       16.000000        9.000000       12.000000        
 4.000000        7.000000       -2.000000       -1.000000        4.000000        1.000000        2.000000        
 6.000000        9.000000        0.000000        1.000000        0.000000        1.000000        0.000000        
 8.000000        8.000000        2.000000        0.000000        4.000000        0.000000        0.000000        
10.000000       11.000000        4.000000        3.000000       16.000000        9.000000       12.000000        

Sigma x : 30.000000
Sigma y: 40.000000
x mean: 6.000000
y mean: 8.000000
Sigma X square: 40.000000
Sigma Y square: 20.000000

Sigma X*Y : 26.000000
Cofficient of regression=0.919239 slope y on x=0.650000
Cofficients are: a=4.100000 b=0.650000
Equation of curve is: y = 4.100000 + 0.650000 * x
Enter value of x for which y need to be calculated:3
y for 3.000000 is 6.050000

*/

#include <stdio.h>
#include <math.h>

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
    float x[n],y[n];

    printf("Enter values of x and y for %d times:\n",n);
    for(i=0;i<n;i++)
    {
        printf("Enter x:");
        scanf("%f",&x[i]);
        printf("Enter y:");
        scanf("%f",&y[i]);

    }

    float sum_x=0,sum_y=0;

    for(i=0;i<n;i++)
    {
        sum_x+=x[i];
        sum_y+=y[i];
    }

    float x_mean=sum_x/n,y_mean=sum_y/n;
    float X[n],Y[n],X2[n],Y2[n],XY[n],sum_X2=0,sum_Y2=0,sum_XY=0;

    for(i=0;i<n;i++)
    {
        X[i]=x[i]-x_mean;
        Y[i]=y[i]-y_mean;
        X2[i]=X[i]*X[i];
        Y2[i]=Y[i]*Y[i];
        XY[i]=X[i]*Y[i];
        sum_X2+=X2[i];
        sum_Y2+=Y2[i];
        sum_XY+=XY[i]; 
    }

    printf("\nTable is:\n");
    printf("\nx        \ty        \tX      \tY      \tX^2        \tY^2      \tX*Y      ");
    for(i=0;i<n;i++)
    {
        printf("\n%9f\t%9f\t%9f\t%9f\t%9f\t%9f\t%9f",x[i],y[i],X[i],Y[i],X2[i],Y2[i],XY[i]);
        
    }

    printf("\n\nSigma x : %f",sum_x);
    printf("\nSigma y: %f",sum_y);
    
    printf("\nx mean: %f",x_mean);
    printf("\ny mean: %f",y_mean);
    printf("\nSigma X square: %f",sum_X2);
    printf("\nSigma Y square: %f",sum_Y2);
    printf("\n\nSigma X*Y : %f",sum_XY);
    

    float r=sum_XY/sqrt(sum_X2*sum_Y2);
    float slope=r*sqrt(sum_Y2)/sqrt(sum_X2);
    float a=slope*(-x_mean)+y_mean;
    float b=slope;

    printf("\nCofficient of regression=%f slope y on x=%f",r,slope);
    printf("\nCofficients are: a=%f b=%f",a,b);

    printf("\nEquation of curve is: y = %f + %f * x",a,b);

    printf("\nEnter value of x for which y need to be calculated:");
    float _x;
    scanf("%f",&_x);

    printf("y for %f is %f",_x,cal_y(_x,a,b));
    return 0;
}