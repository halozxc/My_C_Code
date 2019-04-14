#include<stdio.h>
int main(){
	int i=1,a=0;
	double b=1;
	do
	{
			if(i%2==0){
			a+=i;
		}
		else{
			b*=i;
		}
		i++;
	}
	while(i<=100);
	printf("%d\n",a);
    printf("%d\n",b);
}
