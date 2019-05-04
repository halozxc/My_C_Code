#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	  
       int random_variable = 10+rand()%10;
        int a[random_variable];
	      
	   int sum =0;
       int min =20,max=10;
	   for(int i =1;i<=random_variable;i++){
     
		  int num = 10+rand()%10;    
		    printf("%d\n",num) ;   	
		   a[i-1]=num;
		   sum+=num;
       	if(num>max)
       	max=num;
       	if(num<min)
       	min=num;
	   }
       printf("Max number is:%d,min number is:%d,average is:%.2f",max,min,(float)sum/ random_variable) ;
       return 0;
}
