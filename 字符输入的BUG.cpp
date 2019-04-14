#include <iostream>
int main()
{

using namespace std;
const int ArSize = 20;
char name [ArSize] ;
char dessert [ArSize] ;
cout << "Enter your name.\n";
cin.getline(name,20);
cout << "Enter your favorite dessert.\n";
int num = 0 ;

cin >> num;
cin.get();
cin.getline(dessert,20);
cout << "I have "<< num<<" delicious¡¡"<< dessert ;
cout <<"for you,"<< name << ".\n";
return 0;
} 
