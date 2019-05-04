#include<stdio.h>
double fact(int a){
	double l=1;
	for(int i=a;i>=1;i--)
	l=1.0*l*i;
	return l;
}
int main(){
	int a;
	double s=0;
	scanf("%d",&a); 
	for(int i=a;i>=1;i--)
	s=s+fact(i);
	printf("%.0f",s);
	return 0;
}
