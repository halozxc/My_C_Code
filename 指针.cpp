#include<iostream>
using namespace std;
int main()
{
	int x[2];
	x[0] =25;
int *p=&x[0];
	cout << *p;
	return 0;
}
