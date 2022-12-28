//bisection method x=(a+b)/2

#include <stdio.h>

double f(double x)
{
    return x*x*x-4*x-9;
}

double turncate(double x)
{
    int y= (int)(x*1000);
			double z= (double)y/1000;
			return z;
			
		
}

int isEqual(double arr[3])
{
    
    if(turncate(arr[0])==turncate(arr[1])&&turncate(arr[1])==turncate(arr[2])){return 1;}
    else{return 0;}
}

 
int main()
{
    while(1)
    {
        double arr[3];
        double interval[2];
        printf("Enter value of a and b:\n");

        scanf("%lf%lf",&interval[0],&interval[1]);
        
        if(f(interval[0])*f(interval[1])>=0)
        {
            printf("Wrong interval, Enter another values:");
            continue;
        }

        if(f(interval[1])<0)
        {
            double temp=interval[1];
            interval[1]=interval[0];
            interval[0]=temp;
        }

        arr[0]=interval[0];
        arr[1]=interval[1];

        int itr=0;
        int index=1;
       

        while(!isEqual(arr))
        {
            index=(index+1)%3;
            //printf("%lf=%lf %lf=%lf %lf\n",arr[0],f(arr[0]),arr[1],f(arr[1]),arr[2]);
            arr[index]=(interval[0]+interval[1])/2;

            if(f(arr[index])>0)
            {
                interval[1]=arr[index];
            }
            else
            {
                interval[0]=arr[index];
            }

            itr++;
        }

        printf("\nNumber of iterations:%d\nResult=%lf",itr,turncate(arr[0]));
        break;
        
    }
}