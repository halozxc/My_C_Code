#include<stdio.h>
int main(){
	char x;
	int C=0,c=0,n=0;
   	do{
	 scanf("%c",&x);
		if(x>='0'&&x<='9')
		n++;
		if(x>='a'&&x<='z')
		c++;
	    if(x>='A'&&x<='Z')
		c++;
	}while(x!='q'&&x!='Q');
	printf("数字个数%d",n);
	printf("小写字母个数%d",c);
	printf("大写字母个数%d",C);
}
