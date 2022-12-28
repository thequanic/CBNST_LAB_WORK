#include <stdio.h>

double f(double x)
{
    return 2*x*x*x-2*x-5;
}

double turncate(double x)
{
    int y= (int)(x*1000);
			double z= (double)y/1000;
			return z;
			
		
}

int isEqual(double arr[3])
{
    
    if(turncate(arr[0])==turncate(arr[1]) && turncate(arr[1])==turncate(arr[2]) && turncate(arr[0])==turncate(arr[2])){return 1;}
    else{return 0;}
}

 
int main()
{
    while(1)
    {
        double arr[3];
        double interval[2];
        printf("Enter value of x0 and x1:\n");

        scanf("%lf%lf",&interval[0],&interval[1]);
        
        if(f(interval[0])*f(interval[1])>=0)
        {
            printf("Wrong interval, Enter another values:");
            continue;
        }

        arr[0]=interval[0];
        arr[1]=interval[1];

        int itr=0;
        int temp=1;
       

        while(!isEqual(arr))
        {
            //printf("arr[0]:f(%.3lf)=%.3lf arr[1]:f(%.3lf)=%.3lf arr[2]:%.3lf itr=%d\n",arr[0],f(arr[0]),arr[1],f(arr[1]),arr[2],itr);
            temp=(temp+1)%3;
            arr[temp]=(f(interval[1])*interval[0]-f(interval[0])*interval[1]) /(f(interval[1])-f(interval[0]));

            if(f(arr[temp])>0)
            {
                if(f(interval[0])>0)
                {
                    interval[0]=arr[temp];
                }
                else{
                    interval[1]=arr[temp];
                }
            }
            else
            {
                if(f(interval[0])<0)
                {
                    interval[0]=arr[temp];
                }
                else{
                    interval[1]=arr[temp];
                }
             }

            itr++;
        }

        printf("\nNumber of iterations:%d\nResult=%lf",itr,turncate(arr[0]));
        break;
        
    }
}