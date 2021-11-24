#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
struct point{
    int x;
    int y;
    point(int x,int y){
        this->x = x;
       this->y = y;
    }
};
int main(){
    int n;//井口数
    vector<point> wells;
    cin >> n;
    int miny, maxy;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        wells.push_back(point(x, y));
        if(i ==0){
         maxy=miny = y;
        }
        else
        {
            if(y<miny)
            {
                miny = y;
           }
           if(y>maxy){
               maxy = y;
           }
        }
    }
    int sum = 0;
    int y;
    for (int i = miny; i <= maxy;i++){
        int count = 0;
        for (int j = 0; j < wells.size();j++){
            count += abs(wells[j].y - i);
        }
        if(i ==miny){
            sum = count;

        }
        else
        {
            if(sum>count){
                sum = count;
                y = i;
            }
        }
        
    }
    cout << "min lenth is" << sum << " y is:" << y;
    return 0;
}