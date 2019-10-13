//解决迷宫问题
#include<iostream>
#include<stack>
using namespace std;
struct vector2{
    int x;
    int y;
}tar;
stack<vector2> path;
int map[100][100];
vector2 dir[7];
void dfs(vector2 x){
    //cout<<"stood at"<<x.x<<","<<x.y;
    map[x.x][x.y]=-1;//标记已经走过
    path.push(x);
    if(x.x==tar.x&&x.y==tar.y)
    {
        cout<<"["<<tar.x<<"]["<<tar.y<<"]"<<"find!";
        while(!path.empty())
        {
            vector2 a=path.top();
            path.pop();
           if(path.empty()){
           cout<<"["<<a.x<<"]["<<a.y<<"]"<<endl;
           }
           else{
               cout<<"["<<a.x<<"]["<<a.y<<"]->";
           }

        }
        return;
    }
    for(int i=0;i<8;i++){
        int tx=dir[i].x+x.x;
        int ty=dir[i].y+x.y;
       // cout<<"try"<<tx<<","<<ty<<endl;
        if(map[tx][ty]==0){
            vector2 t;
            t.x=tx,t.y=ty;
            
            dfs(t);
            
            map[tx][ty]=0;
            if(path.empty())
            {
                return;
            }
            path.pop();
        }
        else{
            continue;
        }
        
    }
        return;
}




int main(){
dir[0].x=0,dir[0].y=1;
dir[1].x=1,dir[1].y=1;
dir[2].x=1,dir[2].y=0;
dir[3].x=1,dir[3].y=-1;  
dir[4].x=0,dir[4].y=-1;
dir[5].x=-1,dir[5].y=-1;
dir[6].x=-1,dir[6].y=0;
dir[7].x=-1,dir[7].y=1;
int row=0,colum=0;
cin>>row>>colum;

for(int i=0;i<row;i++){
    for(int j=0;j<colum;j++)
    {
       cin>>map[i][j];
    }
}

cin>>tar.x>>tar.y;
vector2 pos;
pos.x=1,pos.y=1;
dfs(pos);
}