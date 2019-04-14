#include<iostream>
using namespace std;

int main()
{
	float x,y,z,s;
	float cal(float x,float y,float z);
	cin>>x;
	cin>>y;
	cin>>z;
    s=cal(x,y,z);
    cout<< s;
    return 0;
}
float cal(float x,float y,float z)
{
	float s;
	s= x*y*z;
	return s;
}
