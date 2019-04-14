#include<stdio.h>
int main(){
	float mother,father,c;
	char sex,sports,diet;
	printf("this program will predict your height(cm)\n");
	printf("please input mother's height\n");
	scanf("%f",&mother);
    printf("please input father's height\n");
	scanf("%f",&father);
	getchar();
    printf("what's your gender(m/f)?\n");
    scanf("%c",&sex);
    if(sex=='m'){
    	c=(father+mother)*0.54;
	}
	else{
		c=(mother+father*0.923)/2;
	}
getchar();
printf("Do you exercise daily?(y/n)?\n");
scanf("%c",&sports);

if(sports='y')
c=c*1.02;
printf("Do you have healthy diet?(y/n)?\n");
scanf("%c",&diet);
getchar();
if(diet='y')
c=c*1.015;
printf("the result is:%.0fcm",c);
	}
	
