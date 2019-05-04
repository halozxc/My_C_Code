#include<stdio.h>
#include <ctype.h>
int main(){
	char c;
	int sum=0;
	char d=' ';
	do{
		scanf("%c",&c);
		if(isalpha(c)&&!isalpha(d))
		{
		sum++;
	}
	d=c;
	}while(c!='\n');
	printf("%d", sum);
	return 0;
}
