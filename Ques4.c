//program
#include <stdio.h>
#include <math.h>



double f(double x)
{
    // return x*x*x*x-x-10;
    return 3*x-cos(x)-1;
}

double df(double x)
{
    //return 4*x*x*x-1;
    return 3+sin(x);
}

double next(double x)
{
    return x-(f(x)/df(x));
}

double turncate(double x)
{
    int y= (int)(x*1000);
			double z= (double)y/1000;
			return z;
			
		
}

int isEqual(double v1,double v2,double v3)
{
    
    if(turncate(v1)==turncate(v2)&&turncate(v2)==turncate(v3)&&turncate(v1)==turncate(v3)){return 1;}
    else{return 0;}
}

int main()
{
    double x;
    printf("Enter x0:");
    scanf("%lf",&x);

    double v1=x;
    double v2=next(v1);
    double v3;

    int itr=1;

    while(1)
    {
        v3=next(v2);
        printf("%lf\n%lf\n%lf\n",turncate(v1),turncate(v2),turncate(v3));
        itr++;
        if(isEqual(v1,v2,v3))
        {
            break;
        }

        v1=next(v3);
        itr++;
        if(isEqual(v1,v2,v3))
        {
            printf("%lf\n",turncate(v1));
            break;
        }

        v2=next(v1);
        itr++;
        if(isEqual(v1,v2,v3))
        {
            printf("%lf\n",turncate(v2));
            break;
        }


    }

    printf("\nResult is:%lf\nNumber of iterations:%d",turncate(v3),itr);




    return 0;
}
