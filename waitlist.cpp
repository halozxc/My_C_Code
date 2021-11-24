#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int time[10];
    for (int i = 0; i < 10;i++){
        cin >> time[i];
    }
    sort(time, time + 10);
    int waittime[10];
    waittime[0] = 0;
    for (int i = 1; i < 10;i++){
        waittime[i] = waittime[i - 1] + time[i-1];
    }
    auto sum = 0;
    for (int i = 0; i < 10;i++){
        sum += waittime[i];
    }
    sum /= 10;
    cout << sum;
    return 0;
}