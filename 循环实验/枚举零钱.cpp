#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	if(a%10==0){
		for(int i=a/5;i>=1;i--)
		for(int j=(a-5*i)/2;j>=1;j--)
		if((a-5*i-2*j)!=0) 
		printf("%d��5Ԫ��%d��2Ԫ��%d��1Ԫ\n",i,j,a-5*i-2*j);
    }
    
	return 0;
} 
