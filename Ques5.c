//iteration method

#include <stdio.h>
#include <math.h>


double next(double x)
{
    return cbrt(2*x*x+4);
}

double truncate(double x)
{
    int y= (int)(x*1000);
			double z= (double)y/1000;
			return z;
			
		
}

int isEqual(double arr[3])
{
    
    if(truncate(arr[0])==truncate(arr[1])&&truncate(arr[1])==truncate(arr[2])){return 1;}
    else{return 0;}
}

int main()
{
    printf("Enter x0:");
    double x;
    scanf("%lf",&x);

    double arr[3];
    arr[0]=x;
    printf("\nx0=%lf",truncate(arr[0]));
    arr[1]=next(arr[0]);
     printf("\nx1=%lf",truncate(arr[1]));
    arr[2]=next(arr[1]);
     printf("\nx2=%lf",truncate(arr[2]));

    int itr=2;

    while(!isEqual(arr))
    {
        itr++;
        arr[itr%3]=next(arr[(itr+2)%3]);
        printf("\nx%d=%lf",itr,truncate(arr[itr%3]));
    }

    printf("\n\nResult=%lf\nNumber of iterations=%d",truncate(arr[0]),itr);


}