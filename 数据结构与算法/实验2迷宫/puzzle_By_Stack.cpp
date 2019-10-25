//解决迷宫问题
#include<iostream>
#include<stack>
using namespace std;
struct vector2{//该结构体用于存储位置
    int x;
    int y;
}tar;
stack<vector2> path;//用这个栈来存储路径
int map[100][100];
vector2 dir[7];
void dfs(vector2 x){
    //cout<<"stood at"<<x.x<<","<<x.y;
    map[x.x][x.y]=-1;//标记已经走过
    path.push(x);
    if(x.x==tar.x&&x.y==tar.y)//找到出口！！
    {
        cout<<"["<<tar.x<<"]["<<tar.y<<"]"<<"find!";//提示一下
       stack<vector2> result;

       while(!path.empty()){
           result.push(path.top());
           path.pop();
       }
        while(!result.empty())//将栈中的元素逐一输出
        {
            vector2 a=result.top();
            map[a.x][a.y]=88;
            result.pop();
           if(result.empty()){
           cout<<"["<<a.x<<"]["<<a.y<<"]"<<endl;
           }
           else{
               cout<<"["<<a.x<<"]["<<a.y<<"]->";
           }

        }
        return;
    }
    for(int i=0;i<8;i++){//主次尝试各个方向
        int tx=dir[i].x+x.x;
        int ty=dir[i].y+x.y;
       // cout<<"try"<<tx<<","<<ty<<endl;
        if(map[tx][ty]==0){//如果往这个方向可以走的话
            vector2 t;
            t.x=tx,t.y=ty;
            
            dfs(t);//调用自身，尝试下一个点
            
            map[tx][ty]=0;
            if(path.empty())//如果找到了的话，栈会被弹空，故只要返回即可
            {
                return;
            }
            path.pop();//这个点无法到达终点，故弹出；
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
cin>>row>>colum;//都迷宫规格
for(int i=0;i<row;i++){//都迷宫数据
    for(int j=0;j<colum;j++)
    {
       cin>>map[i][j];
    }
}
for(int i=0;i<row;i++){//输出迷宫数据
    for(int j=0;j<colum;j++)
    {
       cout<<map[i][j]<<" ";
    }
cout<<endl;
}

cin>>tar.x>>tar.y;//读出口地址
vector2 pos;
pos.x=1,pos.y=1;//这是默认的起始点
dfs(pos);//开始深搜
for(int i=0;i<row;i++){//输出路径数据
    for(int j=0;j<colum;j++)
    {
       if(map[i][j]==88)
       {
           char a=map[i][j];
           cout<<a<<" ";
       }
       cout<<map[i][j]<<" ";
    
    }
cout<<endl;
}
}
