#include<iostream>
using namespace std;
int main()
{
	int *p = new int;
	*p = 666;
	cout << *p <<endl;
	cout << p <<endl;
	cout<< &p<<endl;
	return 0;
	 
}
