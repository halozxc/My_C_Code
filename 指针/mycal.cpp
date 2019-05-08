#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
float trans(char* x);

int main(int a,char** str){
	
	
	float res;

    res=trans(str[1]);
    printf("%s\n",str[1]);
	printf("%f",res);
}
float trans(char* x)
{
	int i=0;
	float a=0,b=0;
	char* c;
	char d;
	while(*x>='0'&&*x<='9')
	{
	a=a*10+*x++ - '0'; 
	}
    d=*x++;
    while(*x!='\0')
    b=b*10+*x++ -'0';
   printf("%f\n",a);
   printf("%f\n",b);
	switch (d)
	{
     case '+':
		 i=a+b;
		 
		 break;	
	case '-':
		 
		 i=a-b;
		 
		 break;	
	case '*':
		 i=a*b;
		 
		 break;	
		 case '/':
		 i=(float)a/b;
		 
		 break;		 
	}
	return i;
	
}
