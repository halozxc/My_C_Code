#include<iostream>
__int64 n=0;
int hanoi(int n,char x,char y,char z)
{
	if (n==1) 
	printf("%c->%c\n",x,z);
	else
	{
		hanoi(n-1,x,z,y);
			printf("%c->%c\n",x,z);
			n++;
		hanoi(n-1,y,x,z);
	}
}
int main(){
	hanoi(3,'a','b','c');
	printf("%l64d\n",n);
	return 0;
}
