#include<stdio.h>
int main(){
	int i=1,a=0;
	double b=1;
	for(i = 1;i<=100;i++){
		if(i%2==0){
			a+=i;
		}
		else{
			b*=i;
		}
	}
printf("%d\n",a);
printf("%d\n",b);
}
