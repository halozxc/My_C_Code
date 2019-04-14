#include<stdio.h>
int main(){
	int i=1,a=0;
	double b=1;
	while(i<=100){
			if(i%2==0){
			a+=i;
		}
		else{
			b*=i;
		}
		i++;
	}
printf("%d\n",a);
printf("%d\n",b);
}
