#include<bits/stdc++.h>
using namespace std;
int pos;
int mycount;
int charcount;
int numcount;
int leap;
struct treeNode{
    //���ǽ���ֵ
    char data;
    //���¼�˸ýڵ�Ĳ㼶
    int layer;
    //����key
    int key;
    //������ڵ�
    treeNode* left;
    //�����ҽڵ�
    treeNode *right;
};
treeNode* tree_init(char order[]){//�����ȸ����б���
    //cout<<order[pos]<<endl;
    if((*order<'a'||*order>'z')&&(*order<'A'||*order>'Z')&&(*order<'0'||*order>'9')&&*order!='#'){
        cout<<"till the end";//�������е���ײ�
        return NULL;
    }
    
        treeNode* out =(treeNode*)malloc(sizeof(treeNode));
        out->data=order[pos];
        pos++;
        if(out->data=='#'){
           //cout<<"this node without son\n";//������#����ʾ���ӽڵ�Ϊ��
            out=NULL;
            return out;
        }
        else
        {
            //cout<<"keep dig\n";
            out->left=tree_init(order);//���ø��������ӽڵ�
            out->right=tree_init(order);//���ø��������ӽڵ�            
            return out;        
        }
    }
void firstacess(treeNode *x){//�ݹ��������
    if(x==NULL){
        return;//���ڵ�Ϊ���򷵻�
    }
    cout<<x->data;//���ʸ��ڵ��λ��
     if(x->left!=NULL){
        firstacess(x->left);//�������������
    }
     if(x->right!=NULL){
        firstacess(x->right);//�������������
    }
    
    return;
    }
void middleacess(treeNode *x){//�ݹ��������
    if(x!=NULL){     
        if(x->left==NULL&&x->right==NULL)
        {
            leap++;
        }
        middleacess(x->left);//�������������
        cout<<x->key<<",";//���ʸ��ڵ�
        middleacess(x->right);//�������������
    }
    
    return;
    }
void backacess(treeNode *x){//�ݹ�������
     if(x==NULL){
        return;
    }
   
     if(x->left!=NULL){
        backacess(x->left);//�������������
    }
     
     if(x->right!=NULL){
        backacess(x->right);//�������������
    }
     cout<<x->data;//���ʸ��ڵ�
    
    return;
    }

void delete_tree(treeNode *x){//�ݹ�ɾ��
    if(x!=NULL){
        delete_tree(x->left);//ɾ��������
        delete_tree(x->right);//ɾ��������
        free(x);//ɾ�����ڵ�
    }
    return;
}
void Nfirstacess(treeNode *x){//�ǵݹ��������
    stack<treeNode*> path;
    treeNode *p;
    path.push(x);//���ڵ���ջ
    while(!path.empty()){//ֻҪջ����
        p=path.top();
        cout<<p->data;
        path.pop();//��ջ�����ʸýڵ�
        if(p->right!=NULL){
            path.push(p->right);//���ҽڵ���ջ
        }
        if(p->left!=NULL){
            path.push(p->left);//����ڵ���ջ
        }
    }
}
void Nmiddleacess(treeNode *x){//�ǵݹ��������
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
            p=p->left;//������ջ��ڵ�ֱ������Ľڵ�
        }
        p=path.top();
        path.pop();//��ջ��������ڵ�
        cout<<p->data;
        p=p->right;//�����ҽڵ���ջ
    }
}
void Nbackacess(treeNode *x){//�ǵݹ�������
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
            p=path.top()->right;//���������˻ء�����������
    }
        else
        {
            p=NULL;//���������˻ء�������һ��
        }
        
    }
    
}
void levelacess(treeNode *x){//��α���
    queue<treeNode*> path;
    int layer=1;
    x->layer=layer;
    path.push(x);
    treeNode* p;
    p=x;
    cout<<"��1���Ԫ��Ϊ��"<<endl;
    while(!path.empty()){
        p=path.front();
        if(p->layer>layer){
            cout<<endl<<"��"<<p->layer<<"���Ԫ��Ϊ��"<<endl;
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
           return;//һ�������֣�û��Ҫ���룬ֱ�ӷ���
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
           cout<<"�ҵ�";
            if(x->right!=NULL&&x->left!=NULL){
               cout<<"������������"<<endl;
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
                    cout<<"����������"<<endl;
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
                cout<<"����������"<<endl;
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
                 cout<<"û����"<<endl;
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
    cout<<"�ҵ���"<<endl;
}
else{
    cout<<"û�ҵ�"<<endl;
}
cout<<"Ҷ�ӽڵ�����ǣ�"<<leap<<endl;
deleteBST(x,27);
middleacess(x);
return 0;
}