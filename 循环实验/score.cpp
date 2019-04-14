#include<stdio.h>
int main(){

int i=1,j=0;
float s=0,a=0;
while(s>=0){
	printf("please input student%d's score:",i);
	scanf("%f",&s);
	if(s>=0)
	{
		i++;
		a+=s;
		if(s<60)
		j++;
	}
}
printf("average score is:%.2f\n",a/i);
printf("number of people failing:%d",j);
}
