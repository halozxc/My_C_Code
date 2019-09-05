#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
int CalTest(int a,int b,int o)
{
	int back;
	char c;
	float s,r;
	switch (o)
	{
     case 0:
		 s=a+b;
		 c='+';
		 break;
	case 1:
		 if(a<b){
	   	int temp;
	   	temp =a;
	   	a=b;
	   	b=temp;
	   }
		 s=a-b;
		 c='-';
		 break;
		 case 2:
		 s=a*b;
		 c='*';
		 break;
		 case 3:
		 s=(float)a/b;
		 c='/';
		 break;
	}
    printf("%d%c%d=?",a,c,b);
	scanf("%f",&r);

	if(abs(r-s)/s<0.01)
	{
	back=1;
	}
	else {
back=0;
	}
	if(s<1e-7&&r<1e-7)
	back=1;
return back;
}

int main(){
	srand((unsigned)time(0));
	int CalTest(int a,int b);
	int a,b;
    int o;
	int score;
	printf("来做些数学题吧（保留两位小数即可）\n");
	for(int i=1;i<=10;i++)
	{
		a=1+rand()%9;
		b=1+rand()%9;
		o=rand()%4;

	   if(CalTest(a,b))
	   {
	   		printf("right\n");
	   score=score+10;
	   }
	   else{
	   	printf("not correct\n");
	   }
	}
   printf("your total score is %d",score) ;
   return 0;
}
