#include<stdio.h>
#include<math.h>
int main(){
	printf("this is a calculator\n") ;
	float a,b,c;
	c=0;
	char op;
	printf("please input numer 1\n");
	scanf("%f",&a);
	getchar();
	printf("please input the operator\n");
	scanf("%c",&op);
		printf("please input numer 2\n");
	scanf("%f",&b);
	switch (op){
	
		case '+':
			c=a+b;
			break;
		case '-':
			c=a-b;
			break;
		case '*':
		 	c=a*b;
		 	break;
		case '/':
		if (fabs(b) <= 1e-7){
			printf("divisor is zero\n");		
			break;
		}
		else
		c=a/b;
		break;
	
}
printf("%.2f\n",c);
		 		
}

