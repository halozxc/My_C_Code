#include<stdio.h>
int main(){
	char x;
	int C=0,c=0,n=0,o=0;
   	do{
	 scanf("%c",&x);
		if(x>='0'&&x<='9')
		n++;
		else if(x>='a'&&x<='z')
		c++;
	    else if(x>='A'&&x<='Z')
		C++;
		else
		{
		o++;	
		}
	}while(x!='q'&&x!='Q');
	printf("数字个数%d\n",n);
	printf("小写字母个数%d\n",c);
	printf("大写字母个数%d\n",C);
	printf("其他字符个数%d\n",o);
}
