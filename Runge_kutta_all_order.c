#include <stdio.h>

float f(float x, float y)
{
    return (x-y)/2;
}

void order1(float x0, float y0, float xn, float h, float n)
{
    float y;
    int i;
    printf("\n\nx      \ty      ");
    for(i=0;i<n;i++)
    {
        printf("\n%f\t%f",x0,y0);
        y=y0+h*f(x0,y0);
        y0=y;
        x0=x0+h;
    }
    printf("\n\ny at %f: %f",xn,y0);
}

void order2(float x0, float y0, float xn, float h, float n)
{
    float k1,k2;
    int i;
    for(i=0;i<n;i++)
    {
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2,y0+k1/2);
        printf("\nIn %d iteration, x0= %f y0= %f, k1= %f, k2= %f",i,x0,y0,k1,k2);
        y0= y0+k2;
        x0=x0+h;
    }
    printf("\n\ny at %f is: %f",x0,y0);
}

void order3(float x0, float y0, float xn, float h, float n)
{
    float k1,k2,k3;
    int i;
    for(i=0;i<n;i++)
    {
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2,y0+k1/2);
        k3=h*f(x0+h,y0+2*k2-k1);
        printf("\nIn %d iteration, x0= %f y0= %f, k1= %f, k2= %f, k3= %f",i,x0,y0,k1,k2,k3);
        y0= y0+(k1+4*k2+k3)/6;
        x0=x0+h;
    }
    printf("\n\ny at %f is: %f",x0,y0);
}

void order4(float x0, float y0, float xn, float h, float n)
{
    float k1,k2,k3,k4;
    int i;
    for(i=0;i<n;i++)
    {
        k1=h*f(x0,y0);
        k2=h*f(x0+h/2,y0+k1/2);
        k3=h*f(x0+h/2,y0+k2/2);
        k4=h*f(x0,y0+k3);
        printf("\nIn %d iteration, x0= %f y0= %f, k1= %f, k2= %f, k3= %f, k4= %f",i,x0,y0,k1,k2,k3,k4);
        y0= y0+(k1+2*k2+2*k3+k4)/6;
        x0=x0+h;
    }
    printf("\n\ny at %f is: %f",x0,y0);
}

int main()
{
    float x0,y0,xn,h;
    printf("Enter value of x0, y0, xn and h:");
    scanf("%f %f %f %f",&x0,&y0,&xn,&h);
    float n=(xn-x0)/h;

    printf("\nn=%f",n);

    printf("\nMENU");
    printf("\n1.order 1");
    printf("\n2.order 2");
    printf("\n3.order 3");
    printf("\n4.order 4");

    int choice;
    printf("Enter your choice:");

    scanf("%d",&choice);

    switch (choice)
    {
        case 1:{
            order1(x0,y0,xn,h,n);
            break;
        }

        case 2:{
            order2(x0,y0,xn,h,n);
            break;
        }

        case 3:{
            order3(x0,y0,xn,h,n);
            break;
        }

        case 4:{
            order4(x0,y0,xn,h,n);
            break;
        }
    }
}