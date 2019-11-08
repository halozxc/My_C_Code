#include<bits/stdc++.h>
using namespace std;
int pos;
int mycount;
int charcount;
int numcount;
struct treeNode{
    //���ǽ���ֵ
    char data;
    //���¼�˸ýڵ�Ĳ㼶
    int layer;
    //������ڵ�
    treeNode* left;
    //�����ҽڵ�
    treeNode *right;
};
treeNode* tree_init(char order[]){//�����ȸ����б���
    //cout<<order[pos]<<endl;
    if((*order<'a'||*order>'z')&&(*order<'A'||*order>'Z')&&(*order<'0'||*order>'9')&&*order!='#'){
        //cout<<"till the end";//�������е���ײ�
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
        middleacess(x->left);//�������������
        cout<<x->data;//���ʸ��ڵ�
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
int main(){
numcount=0;
charcount=0;
char a[]="";
pos=0;
cin>>a;
treeNode *x=tree_init(a);
mycount=0;
//cout<<x->left->left->data;
cout<<"����һ�����ĵݹ��������"<<endl;
firstacess(x);
cout<<endl<<"����һ�����ķǵݹ��������"<<endl;
Nfirstacess(x);
cout<<endl<<"����һ�����ĵݹ��������"<<endl;
middleacess(x);
cout<<endl<<"����һ�����ķǵݹ��������"<<endl;
Nmiddleacess(x);
cout<<endl<<"����һ�����ĵݹ�������"<<endl;
backacess(x);
cout<<endl<<"����һ�����ķǵݹ�������"<<endl;
Nbackacess(x);
cout<<endl<<"����һ�����Ĳ�α���"<<endl;
levelacess(x);
cout<<endl<<"���ָ���Ϊ��"<<numcount<<",��ĸ����Ϊ��"<<charcount<<endl;
delete_tree(x);//������
return 0;
}