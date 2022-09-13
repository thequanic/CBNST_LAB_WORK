#include <stdio.h>

double f(double x)
{
    return x*x*x-2*x-5;
}

double turncate(double x)
{
    int y= (int)(x*1000);
			double z= (double)y/1000;
			return z;
			
		
}

int isEqual(double arr[3])
{
    
    if(turncate(arr[0])==turncate(arr[1])||turncate(arr[1])==turncate(arr[2])||turncate(arr[0])==turncate(arr[2])){return 1;}
    else{return 0;}
}

 
int main()
{
    while(1)
    {
        double arr[3];
        printf("Enter value of x0 and x1:\n");

        scanf("%lf%lf",&arr[0],&arr[1]);
        
        if(f(arr[0])*f(arr[1])>=0)
        {
            printf("Wrong interval, Enter another values:");
            continue;
        }

        // if(f(arr[1])<0)
        // {
        //     double temp=arr[1];
        //     arr[1]=arr[0];
        //     arr[0]=arr[1];
        // }

        int itr=0;
       

        while(!isEqual(arr))
        {
            //printf("%.3lf=%.3lf %.3lf=%.3lf %.3lf %d\n",arr[0],f(arr[0]),arr[1],f(arr[1]),arr[2],itr);
            arr[2]=(f(arr[1])*arr[0]-f(arr[0])*arr[1]) /(f(arr[1])-f(arr[0]));

            if(f(arr[2])>0)
            {
                if(f(arr[0])>0)
                {
                    double temp=arr[0];
                    arr[0]=arr[2];
                    arr[2]=temp;
                }
                else{
                    double temp=arr[1];
                    arr[1]=arr[2];
                    arr[2]=temp;
                }
            }
            else
            {
                if(f(arr[0])<0)
                {
                    double temp=arr[0];
                    arr[0]=arr[2];
                    arr[2]=temp;
                }
                else{
                    double temp=arr[1];
                    arr[1]=arr[2];
                    arr[2]=temp;
                }
             }

            itr++;
        }

        printf("\nNumber of iterations:%d\nResult=%lf",itr,turncate(arr[0]));
        break;
        
    }
}