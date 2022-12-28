//qauss jordan for solving linear eqautions
#include <stdio.h>
int main()
{
    printf("Enter number of unknowns:");
    int n;
    scanf("%d",&n);
    float eq[n][n+1];
    float unknowns[n];
    int i,j;
    printf("Assuming equation in form ax+by+cz..=d, Enter value of constants:\n");
    for(i=0;i<n;i++)
    {
        printf("Enter %d constants for equation %d:",n+1,i);
        for(j=0;j<n+1;j++)
        {
            scanf("%f",&eq[i][j]);
        }
    }
    int k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            if(i!=k)
            {
                float temp=eq[i][k]/eq[k][k];
                for(j=0;j<n+1;j++)
                {
                    eq[i][j]=eq[i][j]-temp*eq[k][j];
                }
            }
        }
    }
    for(k=0;k<n;k++)
    {
        unknowns[k]=eq[k][n]/eq[k][k];
    }
    printf("\n\nUnknowns are:");
    for(i=0;i<n;i++)
    {
        printf("\nx%d=%f\n",i,unknowns[i]);
    }
}