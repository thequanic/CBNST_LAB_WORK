//Guass forward

#include <stdio.h>
int main()
{
    int i, j;
    int n; 
    printf("Enter number of given values:");
    scanf("%d",&n);
    float x[n];
    float y[n][n];
    printf("Enter x y for %d values:",n);
    for(i=0;i<n;i++)
    {
        printf("Enter x:");
        scanf("%f",&x[i]);
        printf("Enter y:");
        scanf("%f",&y[i][0]);

        for(j=1;j<n;j++){y[i][j]=0;}
    }
    float a; 
    printf("Enter point of interpolation:");
    scanf("%f",&a);
    float h, u, sum, p;
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            y[i][j] = y[i + 1][j - 1] - y[i][j - 1];
        }
    }
    printf("\n The forward difference table is:\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j < n - i; j++) {
            printf("%f\t", y[i][j]);
        }
    }
    int index=0;
    for(i=0;i<n;i++)
    {
        if(x[i]<a)
        {
            index=i;
        }
    }
    p = 1.0;
    sum = y[0][0];
    h = x[1] - x[0];
    u = (a - x[index]) / h;
    int k=0;
    for (j = 1; j < n; j++) { 
        
        if(j%2==0)
        {
            k++;
            p = p * (u - k) / j;
            index--;
        }
        else{
            p = p * (u + k) / j;
        }

        printf("\np*y[index][j]=%f",p * y[index][j]);
        
        sum = sum + p * y[index][j];
        
    }
    printf("\nThe value of y at x=%0.1f is %0.3f", a, sum);
}