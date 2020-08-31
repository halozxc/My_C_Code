#include<iostream>
using namespace std;
void print_subset(int n,int* a,int cur){
   if(cur==n){
       for (int i = 0; i < cur;i++){
           if(a[i]){
               printf("%d ", i);
           }
       }
       printf("\n");
       return;
   }
   a[cur] = 1;
   print_subset(n, a, cur + 1);
   a[cur] = 0;
   print_subset(n, a, cur + 1);
}


int main(){
    int a[11] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    print_subset(10, a, 0);
}