#include<iostream>
#include<string>
using namespace std;
int main(){
string str;
getline(cin,str); 
int i,a=0,b=0,s=0;
for (i=0;i<=str.size();i++){

if (str[i]<='Z'&&str[i]>='A'){

 a++;
 b++;
}
else if(str[i]<='z'&&str[i]>='a')
{
	a++;
	s++;
}
}
cout<<"��ĸ����"<<a<<endl;
cout<<"��д��ĸ"<<b<<endl;
cout<<"Сд��ĸ"<<s<<endl;
return 0; 


}
