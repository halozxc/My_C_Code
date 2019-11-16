#include<bits/stdc++.h>
using namespace std;
int pos;
int mycount;
int charcount;
int numcount;
int leap;
struct treeNode{
    //这是结点的值
    char data;
    //这记录了该节点的层级
    int layer;
    //这是key
    int key;
    //这是左节点
    treeNode* left;
    //这是右节点
    treeNode *right;
};
treeNode* tree_init(char order[]){//利用先根序列遍历
    //cout<<order[pos]<<endl;
    if((*order<'a'||*order>'z')&&(*order<'A'||*order>'Z')&&(*order<'0'||*order>'9')&&*order!='#'){
        cout<<"till the end";//输入序列到达底部
        return NULL;
    }
    
        treeNode* out =(treeNode*)malloc(sizeof(treeNode));
        out->data=order[pos];
        pos++;
        if(out->data=='#'){
           //cout<<"this node without son\n";//读到“#”表示该子节点为空
            out=NULL;
            return out;
        }
        else
        {
            //cout<<"keep dig\n";
            out->left=tree_init(order);//设置该树的左子节点
            out->right=tree_init(order);//设置该树的右子节点            
            return out;        
        }
    }
void firstacess(treeNode *x){//递归先序遍历
    if(x==NULL){
        return;//若节点为空则返回
    }
    cout<<x->data;//访问根节点的位置
     if(x->left!=NULL){
        firstacess(x->left);//先序访问左子树
    }
     if(x->right!=NULL){
        firstacess(x->right);//先序访问右子树
    }
    
    return;
    }
void middleacess(treeNode *x){//递归中序遍历
    if(x!=NULL){     
        if(x->left==NULL&&x->right==NULL)
        {
            leap++;
        }
        middleacess(x->left);//中序访问左子树
        cout<<x->key<<",";//访问根节点
        middleacess(x->right);//中序访问右子树
    }
    
    return;
    }
void backacess(treeNode *x){//递归后序遍历
     if(x==NULL){
        return;
    }
   
     if(x->left!=NULL){
        backacess(x->left);//后序访问左子树
    }
     
     if(x->right!=NULL){
        backacess(x->right);//后序访问右子树
    }
     cout<<x->data;//访问根节点
    
    return;
    }

void delete_tree(treeNode *x){//递归删除
    if(x!=NULL){
        delete_tree(x->left);//删除左子树
        delete_tree(x->right);//删除右子树
        free(x);//删除根节点
    }
    return;
}
void Nfirstacess(treeNode *x){//非递归先序遍历
    stack<treeNode*> path;
    treeNode *p;
    path.push(x);//根节点入栈
    while(!path.empty()){//只要栈不空
        p=path.top();
        cout<<p->data;
        path.pop();//出栈并访问该节点
        if(p->right!=NULL){
            path.push(p->right);//将右节点入栈
        }
        if(p->left!=NULL){
            path.push(p->left);//将左节点入栈
        }
    }
}
void Nmiddleacess(treeNode *x){//非递归中序遍历
    stack<treeNode*> path;
    treeNode* p;
    if(x==NULL){
        return;
    }
    path.push(x);
    p=x->left;
    while(p!=NULL||!path.empty()){
        while(p!=NULL){
            path.push(p);
            p=p->left;//依次入栈左节点直到最左的节点
        }
        p=path.top();
        path.pop();//出栈，访问左节点
        cout<<p->data;
        p=p->right;//将其右节点入栈
    }
}
void Nbackacess(treeNode *x){//非递归后序遍历
    treeNode *p;
    p=x;
    stack<treeNode*> path;
    if(x==NULL)
    {
        return;
    }
    while (p!=NULL||!path.empty())
    {
            while(p!=NULL){
            path.push(p);
            p=p->left?p->left:p->right;
        }
        p=path.top();
        cout<<p->data;
        path.pop();
        if(!path.empty()&&(path.top()->left==p)){
            p=path.top()->right;//从左子树退回。进入右子树
    }
        else
        {
            p=NULL;//从右子树退回。返回上一层
        }
        
    }
    
}
void levelacess(treeNode *x){//层次遍历
    queue<treeNode*> path;
    int layer=1;
    x->layer=layer;
    path.push(x);
    treeNode* p;
    p=x;
    cout<<"第1层的元素为："<<endl;
    while(!path.empty()){
        p=path.front();
        if(p->layer>layer){
            cout<<endl<<"第"<<p->layer<<"层的元素为："<<endl;
            layer++;
        }
        cout<<p->data;
        if(p->data>='0'&&p->data<='9'){
            numcount++;
        }
        if(p->data>='a'&&p->data<='z'||p->data>='A'&&p->data<='Z'){
            charcount++;
        }
        path.pop();
        if(p->left!=NULL){
            p->left->layer=layer+1;
            path.push(p->left);
        }
        if(p->right!=NULL){
            p->right->layer=layer+1;
            path.push(p->right);
        }
    }
}
void InsertBST(treeNode *x,char t,int key){
  
    if(x==NULL){
      
        x=(treeNode*)malloc(sizeof(treeNode));
        x->data=t;
        x->key=key;
        x->left=NULL;
        x->right=NULL;
      

    }
    else
    {
          treeNode *p=x;
    treeNode *q=x;
        while(p!=NULL){
            q=p;
            if(p->key<key){
                p=p->right;
            }
            else if(p->key>key){
                p=p->left;
            }
        else{
           return;//一样的数字，没必要插入，直接返回
          }
        }    
        p=(treeNode*)malloc(sizeof(treeNode));       
        p->data=t;
        p->key=key;
        p->left=NULL;
        p->right=NULL;
        if(p->key<q->key){
            q->left=p;
        }
        else{
            q->right=p;
        }
    }
    return;
}
bool searchBST(treeNode *p,int key){
    treeNode *x=p;
    while(x!=NULL){
        if(x->key==key){
            return true;

        }
        else if(x->key>key)
        {
            x=x->left;

        }
        else if(x->key<key)
        {
            x=x->right;
        }
    }
    return false;
}
void deleteBST(treeNode *p,int key){
     treeNode *x=p;
    treeNode* t=x;
    while(x!=NULL){
        if(x->key==key){
           cout<<"找到";
            if(x->right!=NULL&&x->left!=NULL){
               cout<<"他有左右子树"<<endl;
                treeNode *maxpl=x->left;
                treeNode *xr=x->right;
                while(maxpl->right!=NULL){
                    maxpl=maxpl->right;
                }
                maxpl->right=xr;
                if(t->key>key){
                    t->left=x->left;
                }
                else{
                    t->right=x->left;
                }
                free(x);
            }
            else if(x->right!=NULL){
                    cout<<"他有左子树"<<endl;
                    treeNode* tt=x->left;
                if(t->key>key){
                    t->left=tt;
                    free(x);
                }
                else{
                    t->right=tt;
                    free(x);
                }
            }
            else if(x->left!=NULL){
                cout<<"它有右子树"<<endl;
                treeNode* tt=x->right;
                if(t->key>key){
                    t->left=tt;
                    free(x);
                }
                else{
                    t->right=tt;
                    free(x);
                }
            }
            else{
                 cout<<"没子树"<<endl;
                 if(t->key>key){
                    t->left=NULL;
                }
                else{
                    t->right=NULL;
                }
                free(x);
            }
            return ;

        }
        else if(x->key>key)
        {
            t=x;
            x=x->left;

        }
        else if(x->key<key)
        {
            t=x;
            x=x->right;
        }
        
    }
    return ;
}
int main(){
numcount=0;
charcount=0;
int a=0;
int num=0;
 leap=0;
pos=0;
mycount=0;
cin>>a;

treeNode *x=(treeNode*)malloc(sizeof(treeNode));
x->data='a';
cin>>x->key;
x->left=NULL;
x->right=NULL;

for(int i=1;i<=a;i++){
    cin>>num;
    //cout<<num;
    InsertBST(x,'a',num);

}
InsertBST(x,'a',70);
middleacess(x);
cout<<endl;
if(searchBST(x,12)){
    cout<<"找到了"<<endl;
}
else{
    cout<<"没找到"<<endl;
}
cout<<"叶子节点个数是："<<leap<<endl;
deleteBST(x,27);
middleacess(x);
return 0;
}