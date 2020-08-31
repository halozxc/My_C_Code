#include<iostream>
using namespace std;
int main(){
    int a = (1,2,3,4);
    a *= 2 + (4+6);
    printf("%d %d\n",a,a++) ;
    printf("%d\n", a);
    return 0 ;
}
