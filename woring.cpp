#include<iostream>
#include<math.h>
using namespace std;
int main (){
	int n;
	cin>>n;
int max =0;
	for(int i=1;i<=n/2;i++)
	{
	int j=i,count=0;
    int sum =0;
    while(sum<=n){
       count++;
	   sum=sum+j;
       j++;
    
	}	   
   count--;
   if(count>max)
	max=count; 
}
cout<<max;

}
