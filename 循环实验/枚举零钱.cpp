#include<stdio.h>
int main(){
	int a;
	scanf("%d",&a);
	if(a%10==0){
		for(int i=a/5;i>=1;i--)
		for(int j=(a-5*i)/2;j>=1;j--)
		if((a-5*i-2*j)!=0) 
		printf("%d张5元，%d张2元，%d张1元\n",i,j,a-5*i-2*j);
    }
    
	return 0;
} 
