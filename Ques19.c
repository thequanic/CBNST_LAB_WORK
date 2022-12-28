//parabolic curve fitting

/*
PS E:\vsc2.0> cd "e:\vsc2.0\GitHub\CBNST\CBNST_LAB_WORK\" ; if ($?) { gcc Ques19.c -o Ques19 } ; if ($?) { .\Ques19 }
Enter number of provided x,y values:7
Enter values of x and y for 7 times:
Enter x:1
Enter y:-5
Enter x:2
Enter y:-2
Enter x:3
Enter y:5
Enter x:4
Enter y:16
Enter x:5
Enter y:31
Enter x:6
Enter y:50
Enter x:7
Enter y:73

Table is:

x               y               xy              x^2             x^3             x^4         x^2*y
 1.000000       -5.000000       -5.000000        1.000000        1.000000        1.000000   -5.000000
 2.000000       -2.000000       -4.000000        4.000000        8.000000       16.000000   -8.000000
 3.000000        5.000000       15.000000        9.000000       27.000000       81.000000   45.000000
 4.000000       16.000000       64.000000       16.000000       64.000000       256.000000  256.000000
 5.000000       31.000000       155.000000      25.000000       125.000000      625.000000  775.000000
 7.000000       73.000000       511.000000      49.000000       343.000000      2401.000000 3577.000000

Sigma x : 28.000000
Sigma y: 168.000000
Sigma x*y: 1036.000000
Sigma x square: 140.000000
Sigma x cube: 784.000000
Sigma x to the power 4: 4676.000000
Sigma x square * y: 6440.000000
Normal equations are:
140.000000 * a + 28.000000 * b + 7 * c = 168.000000
784.000000 * a + 140.000000 * b + 28.000000 * c = 1036.000000
4676.000000 * a + 784.000000 * b + 140.000000 * c = 6440.000000
Excuted
Cofficients are: a=2.000006 b=-3.000054 c=-3.999911
Equation of parabola: y = 2.000006 * x^2 + -3.000054 * x + -3.999911
*/
#include <stdio.h>
void gauss_elimination(float eq[3][4],int n,float unknowns[3])
{
    int i,j;
    int k;
    for(k=0;k<n-1;k++)
    {
        for(i=k+1;i<n;i++)
        {
            float temp=eq[i][k]/eq[k][k];
            for(j=0;j<n+1;j++)
            {
                eq[i][j]=eq[i][j]-temp*eq[k][j];
            }
        }
    }
    for(k=n-1;k>=0;k--)
    {
        unknowns[k]=eq[k][n];
        for(j=0;j<n;j++)
        {
            if(k!=j)
            {
                unknowns[k]=unknowns[k]-unknowns[j]*eq[k][j];
            }
        }
        unknowns[k]/=eq[k][k];
    }
    printf("\nExcuted");
}
int main()
{
    printf("Enter number of provided x,y values:");
    int n;
    scanf("%d",&n);
    int i,j;
    float x[n],y[n],xy[n],x2[n],x3[n],x4[n],x2y[n];
    printf("Enter values of x and y for %d times:\n",n);
    for(i=0;i<n;i++)
    {
        printf("Enter x:");
        scanf("%f",&x[i]);
        printf("Enter y:");
        scanf("%f",&y[i]);
        xy[i]=x[i]*y[i];
        x2[i]=x[i]*x[i];
        x3[i]=x2[i]*x[i];
        x4[i]=x3[i]*x[i];
        x2y[i]=x2[i]*y[i];
    }
    float sum_x=0,sum_y=0,sum_xy=0,sum_x2=0,sum_x3=0,sum_x4=0,sum_x2y=0;
    printf("\nTable is:\n");
    printf("\nx        \ty        \txy        \tx^2      \tx^3      \tx^4      \tx^2*y      ");
    for(i=0;i<n;i++)
    {
        printf("\n%9f\t%9f\t%9f\t%9f\t%9f\t%9f\t%9f",x[i],y[i],xy[i],x2[i],x3[i],x4[i],x2y[i]);
        sum_x+=x[i];
        sum_y+=y[i];
        sum_xy+=xy[i];
        sum_x2+=x2[i];
        sum_x3+=x3[i];
        sum_x4+=x4[i];
        sum_x2y+=x2y[i];
    }
    printf("\n\nSigma x : %f",sum_x);
    printf("\nSigma y: %f",sum_y);
    printf("\nSigma x*y: %f",sum_xy);
    printf("\nSigma x square: %f",sum_x2);
    printf("\nSigma x cube: %f",sum_x3);
    printf("\nSigma x to the power 4: %f",sum_x4);
    printf("\nSigma x square * y: %f",sum_x2y);
    printf("\nNormal equations are:");
    printf("\n%f * a + %f * b + %d * c = %f",sum_x2,sum_x,n,sum_y);
    printf("\n%f * a + %f * b + %f * c = %f",sum_x3,sum_x2,sum_x,sum_xy);
    printf("\n%f * a + %f * b + %f * c = %f",sum_x4,sum_x3,sum_x2,sum_x2y);
    float eq[3][4];
    eq[2][0]=sum_x2;eq[2][1]=sum_x;eq[2][2]=n;eq[2][3]=sum_y;
    eq[1][0]=sum_x3;eq[1][1]=sum_x2;eq[1][2]=sum_x;eq[1][3]=sum_xy;
    eq[0][0]=sum_x4;eq[0][1]=sum_x3;eq[0][2]=sum_x2;eq[0][3]=sum_x2y;
    float unknowns[3];
    gauss_elimination(eq,3,unknowns);
    printf("\nCofficients are: a=%f b=%f c=%f",unknowns[0],unknowns[1],unknowns[2]);
    printf("\nEquation of parabola: y = %f * x^2 + %f * x + %f",unknowns[0],unknowns[1],unknowns[2]);
    return 0;
}