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
	printf("���ָ���%d\n",n);
	printf("Сд��ĸ����%d\n",c);
	printf("��д��ĸ����%d\n",C);
	printf("�����ַ�����%d\n",o);
}
