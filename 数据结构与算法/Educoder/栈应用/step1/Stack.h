#ifndef _STACK_H_
#define _STACK_H_
 
#include <iostream>
using namespace std;

typedef int DataType;
 
//采用链式栈 
struct node{
   DataType element;  //数据元素 
   struct node *next; //指向下一个数据元素的指针 
};

typedef struct node *PtrToNode;
typedef struct node * Stack;
 
/*
   函数名：isEmpty 
   函数功能：判定栈是否为空 
   函数参数：栈头结点指针 
   返回值：若栈为空，则返回1，否则返回0
*/
int isEmpty(Stack s) 
{
    //此处请填写代码，用于实现判定栈是否为空的功能
    /**********  Begin  **********/
    if(s==NULL){
        return 1;
    }
    else{
        return 0;
    }
    /**********  End  **********/
}

 

/*
   函数名：createStack 
   函数功能：创建一个空栈，实际上只需要初始化栈头结点 
   函数参数：无 
   返回值：栈头结点指针 
*/
Stack createStack(void)  
{
    //此处请填写代码，用于创建一个空的链栈
    /**********  Begin  **********/
     Stack S=(struct node*)malloc(sizeof(struct node));
     S=NULL;
     return S;
    /**********  End  **********/
}

/*
   函数名：push 
   函数功能：向栈中压人一个数据元素值为x 
   函数参数：待压栈的数据元素，栈头结点指针 
   返回值：无
*/
void push(DataType  x,Stack s) 
{
	//表头作为栈顶，此处请填写代码实现压栈功能
    /**********  Begin  **********/
    Stack P=(struct node*)malloc(sizeof(struct node));
    P->element=x;
   P->next=s;
   s=P;
    /**********  End  **********/
}

/*
   函数名：pop 
   函数功能：弹出栈顶元素并返回元素值 
   函数参数：栈头结点指针 
   返回值：栈顶元素的值 
*/
DataType pop(Stack s) 
{
   //此处请填写代码实现出栈并返回栈顶元素的功能，若栈为空，则返回-1
   /**********  Begin  **********/
DataType x=s->element;
 Stack p=s;
 s=s->next;
 free(p);
 return x;
   
   /**********  End  **********/
}

/*
   函数名：convert10to2
   函数功能：将十进制数x转换为二进制并输出 
   函数参数：十进制数x 
   返回值：无 
*/
void convert10to2(int x)
{
	//此处请填写代码实现将参数x转换为二进制并输出的功能，请使用上述栈的基本操作实现
    /**********  Begin  **********/
  Stack s=createStack();
   while(x!=0){
   push(x%2,s);
   x=x/2;
   } 
   while(isEmpty(s))
   {
      cout<<pop(s);
   } 
    /**********  End  **********/
}
#endif

