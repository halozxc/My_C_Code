#include<bits/stdc++.h>
using namespace std;
struct Status{//值为1则是 on the north，值为0则是 on the south
    int farmer;
    int wolf;
    int sheep;
    int forge;
    
};
struct PStatus{
    Status data;
    PStatus* next;
};
struct myqueue{
    
    PStatus* head;
    PStatus* tail;
    int length;
};
myqueue *path;
int book[16]={0};
PStatus mymap[100];
 int mycount;
 int head;

myqueue* myqueue_init(){
    myqueue* x;
    x->head=NULL,x->tail=NULL, x->length=0;
    return x;
}
int myqueue_length(myqueue x)
{
   return x.length; 
}
void myqueue_push(myqueue *x,PStatus* T){
    if(x->length==0){
        x->tail=x->head=T;
    }
    else{
        x->tail->next=T;
        x->tail=x->tail->next;
    }
    x->tail->next=NULL;
    
    x->length++;
    cout<<"push!"<<endl;
}
Status myqueue_head(myqueue* x){
    return x->head->data;
}
bool myqueue_pop(myqueue* x){
    if(x->length==0){
        return false;
    }
    else{
        PStatus *t=x->head;
        x->head=x->head->next;
        free(t);
        x->length--;
        cout<<"pop"<<endl;
        return true;
    }

}
bool judge(Status x){
    //🐏和🐺不可以在一起
    //🐏和🌼不可以在一起
    if((x.farmer!=x.wolf&&x.wolf==x.sheep||x.farmer!=x.sheep&&x.sheep==x.forge)){
        cout<<"bad way!"<<endl;
        return false;
    }
    else{
        cout<<"good way!";
        return true;
    }
}
int encoder(Status x){
    return x.farmer*8+x.forge*4+x.sheep*2+x.wolf;
}
Status passriver(Status x,int n){//过河时的重新编码
    int a;
    switch (n)//对于不合法的过和行为自动视为只让farmer过河
    {
    case 1 :
         if(x.farmer==x.wolf)
         {
             a=x.wolf;
            x.wolf=a==1?0:1;
         }
        break;
    case 2 :
         if(x.farmer==x.sheep)
         {
             a=x.sheep;
            x.sheep=a==1?0:1;
         }
         break;
    case 3 :
         if(x.farmer==x.forge)
         {
             a=x.forge;
            x.forge=a==1?0:1;
         }
        break;
    }
    a=x.farmer;
    x.farmer=a==1?0:1;
    return x;
}
void wfs(Status x){
 book[encoder(x)]=1;
 path=myqueue_init();
 
 mycount=1;
  head=0;
mymap[0].data=x;
mymap[0].next=NULL;
 
 PStatus* startp=(PStatus*)malloc(sizeof(PStatus));//塞一个数据到队列里
 startp->data=x;
 myqueue_push(path,startp);
 cout<<path->length<<endl;
 while(path->length!=0){
     for(int i=1;i<4;i++){
         Status p=passriver(myqueue_head(path),i);
         
         //cout<<"this is"<<judge(p)<<endl;
         if(judge(p)&&book[encoder(p)]==0){
             PStatus *pp=(PStatus*)malloc(sizeof(PStatus));
             pp->data=p;
             pp->next=NULL;
             myqueue_push(path,pp);
             book[encoder(p)]=1;
             mymap[mycount].data=p;
             mymap[mycount].next=mymap+head;
             mycount++;
             cout<<p.farmer;
             cout<<p.wolf;
             cout<<p.sheep;
             cout<<p.forge;
             cout<<endl;
             //cout<<p.farmer<<" "<<p.wolf<<" "<<p.sheep<<" "<<p.forge<<endl;
         }
         if(p.farmer==0&&p.forge==0&&p.sheep==0&&p.wolf==0){
         return;
         }
     }
    myqueue_pop(path);
    head++;
 }
return;
}
void printstatus(Status x)
{
    cout<<"north side: ";
    if(x.farmer==0)
    cout<<"farmer ";
    if(x.wolf==0)
    cout<<"wolf ";
    if(x.sheep==0)
    cout<<"sheep ";
    if(x.forge==0)
    cout<<"forge ";
    cout<<",";
     cout<<"south side: ";
    if(x.farmer==1)
    cout<<"farmer ";
    if(x.wolf==1)
    cout<<"wolf ";
    if(x.sheep==1)
    cout<<"sheep ";
    if(x.forge==1)
    cout<<"forge ";
    cout<<endl;
}
void resultout(PStatus* x){//输出每一步的
    cout<<"farmer with wolf,sheep and forge waiting on the north"<<endl;
    int n=0;
    while(x!=NULL){
        switch (n%3)
        {
        case 1/* constant-expression */:
            cout<<"than ";
            break;
        case 2/* constant-expression */:
            cout<<"next ";
            break;
        
        
        default:
            break;
        }
        n++;
        if(x->next!=NULL){
        cout<<"farmer";
        if(x->next->data.wolf!=x->data.wolf)
        cout<<" with wolf";
        if(x->next->data.sheep!=x->data.sheep)
        cout<<" with sheep";
        if(x->next->data.forge!=x->data.forge)
        cout<<" take forge";
        if(x->next->data.farmer-x->data.farmer==1){
            cout<<" reach south"<<endl;
        }
        else{
            cout<<" back to north"<<endl;
        }
        }
        else{
            cout<<"finally"<<endl;
            if(x->data.farmer==0)
            {
                cout<<"farmer on the north"<<endl;
            }
            else
            {
                cout<<"famer on the south"<<endl;
            }
            if(x->data.sheep==0)
            {
                cout<<"sheep on the north"<<endl;
            }
            else
            {
                cout<<"sheep on the south"<<endl;
            }
            if(x->data.wolf==0)
            {
                cout<<"wolf on the north"<<endl;
            }
            else
            {
                cout<<"wolf on the south"<<endl;
            }if(x->data.forge==0)
            {
                cout<<"forge on the north"<<endl;
            }
            else
            {
                cout<<"forge on the south"<<endl;
            }
        }
         
    x=x->next;
    printstatus(x->data);
    }

}
void dfs(Status x){
    for(int i=1;i<4;i++){

    }
}
int main(){
Status x;
x.farmer=1,x.forge=1,x.sheep=1,x.wolf=1;

//宽搜输出
wfs(x);
resultout(mymap+mycount-1);
}