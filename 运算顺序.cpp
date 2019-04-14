#include<iostream>
#include<string>
using namespace std;
int mian(){
	string s="world";
	string i=s+s[s.size()-1]=='s'?"":"s";
	return 0;
}
