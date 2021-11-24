#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main(){
    string sequence="";
    cin >> sequence;
    int num=stoi(sequence);
    
    int n = sequence.size();
    int numarrary[n + 1];
    int m = n;
    while (num != 0){
        numarrary[m] = num % 10;
        num = num / 10;
        m--;
    }
    int factorial[n+1];
    int book[n + 1];
    int value[n + 1];
    book[0] = -1;
    book[1] = 0;
    value[0] = value[1] = 0;
    factorial[0]= factorial[1] = 1;
    for (int i = 2; i <= n;i++){
        factorial[i] = i * factorial[i - 1];
        book[i] = i- 1;
        value[i] = 0;
    }
    int sum = 0;
    for (int i = 1; i < n+1;i++){
        int p = numarrary[i];
        value[i] = book[p];
        sum += book[p] * factorial[n - i];
        book[p] = -1;
        for (int j = p + 1; j <= n ;j++){
           if(book[j]>0)
           {
               book[j]--;
           }
            
        }
    }
    //到此为止字典序已求出
    cout << sum<<endl;
    //求下一个排列
    int key = 0;
    book[numarrary[n]] = 1;
    for (int i = n-1; i >= 1;i--){
        book[numarrary[i]] = 1;
        if(numarrary[i]<numarrary[i+1]){
           
            key = i;
            break;
        }
    }
    for (int i =numarrary[key]+1; i <= n;i++){
     if(book[i]==1){
         numarrary[key] = i;
         book[i] = -1;
         break;
        }
    }
    int k = 1;
    for (int i = key+1; i <= n;i++){
        
        for (int j=k ; j <= n;j++){
            if(book[j]==1){
                numarrary[i] =j ;
                book[j] = -1;
                k = j;
                break;
            }
        }
    }
    for (int i = 1; i <= n;i++){
        cout << numarrary[i];
    }
    cout << endl;
    return 0;
}