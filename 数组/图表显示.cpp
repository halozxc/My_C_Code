#include<stdio.h>
#include<stdlib.h>
int main(){
	int rnum ;
	int score[40];
	int count[11]={0};
	for(int i=1;i<=40;i++)//��ֵ 
	{
		score[i-1]=1+rand()%10;
     printf("%d\n",score[i-1]);
	}

	for (int i=0; i<40; i++)//ͳ�� 
	{
			count[score[i]] ++;
	}
   	printf("Grade        Count	   Histogram\n");
   for(int i =1;i<=10;i++)//��ӡ��� 
   {
   		printf("%d		 %d	    ",i,count[i]);
	    for(int j=1;j<=count[i];j++)
		{
	   	printf("*");
	    } 
		printf("\n");   
   }
    
}
