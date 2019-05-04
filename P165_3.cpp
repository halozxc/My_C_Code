#include<stdio.h>
int main(){
	int a[3][3];
	for(int i=0;i<=8;i++)
	scanf("%d",&a[i]);
    printf("%d",a[1][1]+a[2][2]+a[3][3]+a[1][3]+a[3][1]);
}

