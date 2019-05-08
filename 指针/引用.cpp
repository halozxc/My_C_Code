#include<iostream>
using namespace std;
void change(int&a,int&b)
{
int c;
c=a;
a=b;
b=c;	
}
int main(){
	int a=100,b=200;
	change(a,b);
	cout<<"a:"<<a<<"b:"<<b<<endl; 
}
