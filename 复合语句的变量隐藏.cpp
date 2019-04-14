#include<iostream>
using std::cout;
using std::endl;
int x;
int main()
{
	x = 25;
	cout<<x<<endl;
	{
		int x = 23;
		cout << x <<endl;
		 
	}
	cout << x << endl;
	return 0;
 } 
