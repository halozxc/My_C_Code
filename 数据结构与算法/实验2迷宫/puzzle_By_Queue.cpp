#include<bits/stdc++.h>
using namespace std;
int mmap[100][100]={1};
int pathBook[100][100]={0};
struct vector2{
    int x;
    int y;
};
struct Pvector2{
    vector2 point;
    Pvector2 *last;
};
vector2 dir[3],dem;
queue<vector2> path;//队列
Pvector2 *h;
Pvector2* wfs(vector2 pos,vector2 tar)
{
    path.push(pos);
    pathBook[pos.x][pos.y]=1;
    Pvector2 h[dem.x*dem.y];//这个数组用来记录路径
int insertpos=1,poppos=0;//前面那个变量指的是前缀的位置，后面那个指的是目前遍历到的点位置

    h->point.x=pos.x,h->point.y=pos.y;
    h->last=NULL;
   
    while(!path.empty())
    {
        for(int i=0;i<8;i++){
              vector2 temp;
              temp.x=path.front().x+dir[i].x,temp.y=path.front().y+dir[i].y;//得到一个新的点的坐标
              if(mmap[temp.x][temp.y]==0&&pathBook[temp.x][temp.y]==0&&temp.x<dem.x&&temp.y<dem.y&&temp.x>=0&&temp.y>=0)//该点不是障碍物且没有被走过
              {
               
                path.push(temp);//入队
                h[insertpos].point.x=temp.x,h[insertpos].point.y=temp.y;
                h[insertpos].last=h+poppos;
                pathBook[temp.x][temp.y]=1;//将这个点标记为已走过
                if(temp.x==tar.x&&temp.y==tar.y)
                {
                    return h+insertpos;
                }    
                 insertpos++;
              }
              else{//不符合就跳过
              continue;
            }
        }
      path.pop();
      poppos++;
    }
    return NULL;
}
Pvector2* reverse(Pvector2* head){

    Pvector2* p,*q,*pr; 

    p = head->last; 

    q = NULL;  

    head->last = NULL; 

    while(p){   

        pr = p->last;    

        p->last = q;    

        q = p;   

        p = pr;  

   }  

    head->last = q;  

    return head;

}

int main(){
    dir[0].x=0,dir[0].y=1;
    dir[1].x=1,dir[1].y=0;
    dir[2].x=-1,dir[2].y=0;
    dir[3].x=0,dir[3].y=-1;  
    
    vector2 tar,pos;
    cin>>dem.x>>dem.y;
    cout<<dem.x<<dem.y;
    for(int i=0;i<dem.x;i++){
        for(int j=0;j<dem.y;j++){
            cin>>mmap[i][j];
        }
    }
    for(int i=0;i<dem.x;i++){
        for(int j=0;j<dem.y;j++){
            cout<<mmap[i][j]<<" ";
        }
    cout<<endl;
    }
    cin>>pos.x>>pos.y;
    cin>>tar.x>>tar.y;
    Pvector2 *result=wfs(pos,tar);
   cout<<"The path is:";
  
  Pvector2* head=(Pvector2*)malloc(sizeof(Pvector2));
  head->last=result;
  result=reverse(head);
    
   result=result->last;
    while(result!=NULL)
    {
        mmap[result->point.x][result->point.y]=-1;
        if(result->last==NULL){
            cout<<"["<<result->point.x<<"]["<<result->point.y<<"]"<<endl;
        }
        else
        {
            cout<<"["<<result->point.x<<"]["<<result->point.y<<"]->";
        }
        result=result->last;
    }
     for(int i=0;i<dem.x;i++){
        for(int j=0;j<dem.y;j++){
            cout<<mmap[i][j]<<" ";
        }
    cout<<endl;
    }

}