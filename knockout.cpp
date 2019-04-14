#include<iostream>
#include<vector>
using namespace std;
int ciradd(int a,int b){
	if (a==b){
		a=1;
	}
	else{
		a+=1;
	} 
return a ;
}
void knockout(int n,int m){
;
	int pla[n+1],book[n+1]={0},count=0,num=1,result[n+1]={0};
int i;
	for( i=1;i<=n;i++)
{ 
	  pla[i]=i;
    }
i=0;
while(count==n){
	 i=ciradd(i,n);
	if(book[i]!=1&&num!=m){
	num	=ciradd(num,m);
	}
	else if(book[i]!=1&&num==m)
	book[i]=1;
	
	count+=1;
result[count]=i;
	num	=ciradd(num,m);
	}
for(i=1;i<=m;i++)
cout<<result[i]<<endl;

}
int main(){
	int a,b;
cin>>a>>b;
	knockout(a,b);
	return 0;
}
