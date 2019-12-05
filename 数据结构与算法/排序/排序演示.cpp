
#include<time.h>
#include<stdio.h>
#include<windows.h>
using namespace std;
void graphic(int a[],int max)
 {
     system("cls");
 	int length= 25;
	 	 for(int i =1;i<=max;i++)
 	{
	 	for(int j=0;j<length;j++)	
	   {
		  	if(a[j]>=(max+1-i))
			{
				printf("*");
			}	
			 	else
			{
			 	printf(" ");
		    }
		}
		printf("\n");
	 
	}

	
 }
int main(){
	int a[25];
	int max=0;
	for(int i=0;i<=24;i++)
	{
	a[i]=rand()%20;
    if(a[i]>max)
    max=a[i];
}
	for(int i=0;i<=24;i++)
	{
		for(int j=24;j>=i;j--)
	{
		if(a[j]<a[j-1]){
			int t=0;
			t=a[j-1];
		a[j-1]=a[j];
		a[j]=t;
		graphic(a,25);
		}
	}
	}
}
