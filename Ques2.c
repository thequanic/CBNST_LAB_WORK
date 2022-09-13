#include <stdio.h>
int main()
{
    float x;
    printf("Enter number:");
    scanf("%f",&x);
    //printf("%f",x);

	printf("Enter your choice:\n1.turncate\n2.round off\n");
	
	int ch;
	scanf("%d",&ch);
	
	switch(ch){
		case 1: {
			int y= (int)(x*10000);
			float z= (float)y/10000;
			printf("Turncate value is:%f",z);
			
			break;
		}
		case 2:{
			int y= (int)(x*100000);
			int temp= y%10;
			y=y/10;
			if(temp>5)
			{
				float z= (float)y/10000;
				z+=0.0001;
				printf("Roundoff value is:%f",z);
			}
			else
			{
				float z= (float)y/10000;
				printf("Roundoff value is:%f",z);
			}
			
			break;
		}
	}
}


