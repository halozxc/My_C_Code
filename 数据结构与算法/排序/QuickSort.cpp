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
void quicksort(int a[],int min,int max){
    int i,j,temp;
    if(max<=1)
    return;
    i=min,j=max;
    temp=a[i];
    while(i!=j){
        while(i<j&&a[j]>=temp){
            j--;
        }
        if(i<j){
            a[i++]=a[j];
        }
        while(i<j&&a[i]<=temp){
            i++;
        }
        if(i<j){
            a[j--]=a[i];
        }
        a[i]=temp;
         graphic(a,max-min+1);
        quicksort(a,min,i-1);
        quicksort(a,i+1,max);
        return;
    }

}
int main(){
   int  a[10]={22,23,1,45,33,27,87,45,99,61};
   quicksort(a,0,9);
  for(int i=0;i<=9;i++){
      printf("%d",a[i]);
  }
   return 0;
}