#include<iostream>
#include<cmath>
 bool judgeSquareSum(int c) {
       int x  = sqrt(c);
       for(int i=1;i<=x;i++ ){
           float y = c-i*i;
           float z = sqrt(y);
           if(floor(z)==z){
               return true;
           }
       }
    return false;
    }
int main(){
    int c;
    std::cin >> c;
   bool a= judgeSquareSum(c);
    return 0;
}