#include<iostream>
#include<cstring>
#include<map>
using namespace std;
bool is_prime(int n){
    for (int i = 2; i * i < n;i++){
        if(n%i==0){
            return false;
            break;
        }
    }
    return true;
}
int main(){
    map<int, int> dic;
    dic[1] = 0;
    dic[2] = 1;
    int a[10] = {1, 2, 3, 4, 2, 3, 5, 6, 7 };
    printf("%d", a[1]);
    return 0;
}

