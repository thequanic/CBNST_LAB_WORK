#include <stdio.h>

int main()
{
    int i,j;
    int n; 
    printf("Enter number of given values:");
    scanf("%d",&n);

    float x[n];
    float y[n];

     printf("Enter x y for %d values:",n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter x:");
        scanf("%f",&x[i]);
        printf("Enter y:");
        scanf("%f",&y[i]); 
    }

    printf("\nEntered table is:");
    printf("\n\nx                y");
    for(i=0;i<n;i++)
    {
        printf("\n%f        %f",x[i],y[i]);
    }

    float a; 

    printf("\n\nEnter point of interpolation:");
    scanf("%f",&a);

    float sum=0;

    for(i=0;i<n;i++)
    {
        float temp=1;
        for(j=0;j<n;j++)
        {
            if(i!=j)
            {
                temp=temp*(a-x[j])/(x[i]-x[j]);
            }

        }
        temp*=y[i];
        sum+=temp;
    }

    printf("Value of y for %f is %f\n",a,sum);
    return 0;
}