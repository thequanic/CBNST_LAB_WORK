//newton backward method

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
        printf("\nEnter x:");
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
        for (i = n-1; i >= 0+j; i--) {
            y[i][j] = y[i][j - 1] - y[i-1][j - 1];
           
        }
    }
    printf("\n The backward difference table is:\n");
    for (i = 0; i < n; i++) {
        printf("\n");
        for (j = 0; j <n; j++) {
            printf("%f\t", y[i][j]);
        }
    
    }
    p = 1.0;
    sum = y[n-1][0];
    h = x[1] - x[0];
    u = (a - x[n-1]) / h;
    //printf("\nu=%f\n",u);
    for (j = 1; j < n; j++) {

       // printf("\n%f %f",p,y[n-1][j]);
        p = p * (u + j-1) / j;
        sum = sum + p * y[n-1][j];
    }
    printf("\nThe value of y at x=%0.1f is %0.3f", a, sum);
}