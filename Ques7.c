//qauss seidal
#include <stdio.h>
double truncate(double x)
{
    int y= (int)(x*1000);
			double z= (double)y/1000;
			return z;
			
		
}
int isEqual(double arr[],double arr1[])
{
    
    if(truncate(arr[0])==truncate(arr1[0])&&truncate(arr[1])==truncate(arr1[1])&&truncate(arr[2])==truncate(arr1[2]))
    {return 1;}
    else{return 0;}
}
int main()
{
    int n;
    printf("Enter number of unknowns:");
    scanf("%d",&n);
    double eq[n][n+1];
    double unknowns[n],unknowns_pre[n];
    int i,j;
    printf("Assuming equation in form ax+by+cz..=d, Enter value of constants:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter %d constants for equation %d:",n+1,i);
        for(j=0;j<n+1;j++)
        {
            scanf("%lf",&eq[i][j]);
        }
    }
    printf("Enter initial quess values for unknowns:");
    for(i=0;i<n;i++)
    {
        scanf("%lf",&unknowns[i]);
    }
    int itr=0;
    while(!isEqual(unknowns,unknowns_pre))
    {
        itr++;
        for(i=0;i<n;i++)
        {
            unknowns_pre[i]=unknowns[i];
        }
        for(i=0;i<n;i++)
        {
            unknowns[i]=eq[i][n];
            for(j=0;j<n;j++)
            {
                if(i!=j)
                {
                    unknowns[i]-=eq[i][j]*unknowns[j];
                }
            }
            unknowns[i]/=eq[i][i];

        }
    }
    printf("\nUnknowns are:\n");
    for(i=0;i<n;i++)
    {
        printf("x%d=%lf\n",i,truncate(unknowns[i]));
    }
    printf("\nNumber of iterations used:%d\n\n",itr);
}