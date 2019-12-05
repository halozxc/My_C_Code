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