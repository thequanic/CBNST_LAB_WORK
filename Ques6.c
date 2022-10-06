//qauss elimation for solving linear eqautions
#include <stdio.h>

int main()
{
    printf("Enter number of unknowns:");
    int n;
    scanf("%d",&n);

    float eq[n][n+1];
    float unknowns[n];

    int i,j;
    printf("Assuming equation in form ax+by+cz..=d, Enter value of constants:");
    for(i=0;i<n;i++)
    {
        printf("\nEnter %d constants for equation %d:",n+1,i);
        for(j=0;j<n+1;j++)
        {
            scanf("%f",&eq[i][j]);
        }
    }

    int k;
    for(k=0;k<n-1;k++)
    {
        for(i=k+1;i<n;i++)
        {
            for(j=0;j<n+1;j++)
            {
                eq[i][j]=eq[i][j]-(eq[i][k]/eq[k][k])*eq[k][j];
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for (j=0;j<n+1;i++)
        {
            printf("%f",eq[i][j]);
        }
        printf("\n");
    }

    for(k=n-1;k>=0;k--)
    {
        for(j=0;j<n;j++)
        {
            if(k!=j)
            {
                unknowns[k]=eq[k][n]-unknowns[j]*eq[k][j];
            }
        }

        unknowns[k]/=eq[k][k];
    }

    printf("\n\nUnknowns are:");
    for(i=0;i<n;i++)
    {
        printf("\nx%d=%f",i,unknowns[i]);
    }
     


}