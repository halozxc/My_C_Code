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
	printf("���ָ���%d",n);
	printf("Сд��ĸ����%d",c);
	printf("��д��ĸ����%d",C);
}
