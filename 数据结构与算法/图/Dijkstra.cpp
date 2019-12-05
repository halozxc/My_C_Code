#include<bits/stdc++.h>
using namespace std;
const int board=100;
int main(){
    long long map[board][board];
    int dis[board],book[board],u,v,t1,t2,t3,x,y,min,s;
    vector<int> path[board];
    long long inf=99999;
    for(int i=0;i<board;i++){
        for(int j=0;j<board;j++){
        map[i][j]=inf;
        
        if(i==j){
            map[i][j]=0;
        }
        
    }    
    }
    cin>>u>>v>>s;
    for(int i=1;i<=v;i++){
        cin>>t1>>t2>>t3;
        map[t1][t2]=t3;
    }

    for(int i=1;i<=u;i++){
        dis[i]=map[s][i];
    
    }
    book[1]=1;
    
    for(int i=1;i<u;i++){
        min=inf;
        for(int j=1;j<=u;j++){
            if(book[j]==0&&dis[j]<min){
                min=dis[j];
                x=j;
            }
        }
        book[x]=1;
        for(y=1;y<=u;y++){
            if(map[x][y]<inf){
                if(dis[y]>dis[x]+map[x][y]){
                    dis[y]=dis[x]+map[x][y];
                    path[y].push_back(x);
                }
            }
        }
    }
  
    for(int i=1;i<=u;i++){
        
        cout<<s<<"µ½"<<i<<"µÄ¾àÀëÎª"<<dis[i]<<endl;
        cout<<"path is"<<i<<",";
        for(int j=0;j<path[i].size();j++){
            cout<<path[i][j]<<",";
        }
        cout<<i<<endl;
    }
    return 0;
}
