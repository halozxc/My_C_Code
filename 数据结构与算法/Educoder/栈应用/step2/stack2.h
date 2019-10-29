#ifndef _STACK_H_
#define _STACK_H_
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef char DataType;
 
//采用链式栈 
struct node{
    DataType element;  //数据元素 
	struct node *next; //指向下一个数据元素的指针 
};

typedef struct node *PtrToNode;
typedef PtrToNode Stack;
 
/*
   函数名：isEmpty 
   函数功能：判定栈是否为空 
   函数参数：栈头结点指针 
   返回值：若栈为空，则返回1，否则返回0
*/
int isEmpty(Stack s) 
{
    return  s->next ==NULL;
}

/*
   函数名：createStack 
   函数功能：创建一个空栈，实际上只需要初始化栈头结点 
   函数参数：无 
   返回值：栈头结点指针 
*/
Stack createStack(void)  
{
	Stack s ;
	s =new struct node;
	s->next = NULL;
	s->element =0;
	return s;
}

/*
   函数名：push 
   函数功能：向栈中压人一个数据元素值为x 
   函数参数：待压栈的数据元素，栈头结点指针 
   返回值：无
*/
void push(DataType  x,Stack s) 
{
	//表头作为栈顶
    PtrToNode temp ;
 	temp=new struct node;
 	temp->element = x;
 	temp->next = s->next;
 	s->next = temp;
}

/*
   函数名：pop 
   函数功能：弹出栈顶元素并返回元素值 
   函数参数：栈头结点指针 
   返回值：栈顶元素的值 
*/
DataType pop(Stack s) 
{
	PtrToNode temp;
	int t;
	if(isEmpty(s)==0)
  	{
  		temp = s->next;
  		t = temp->element;
  		s->next = temp->next;
  		free(temp);
 		 return t;
 	}
}

DataType top(Stack s) 
{
	if(isEmpty(s)==0)
  	{
    	return s->next->element ;
  	}
}
/*
   函数名：judgeCha
   函数功能：判断运算符的优先级
   函数参数：左运算符与右运算符
   返回值：1 表示 左运算符较低  0 表示右运算符高
*/
int judgeCha(char left,char right){
	if(left == '+' || left == '-') {
		//如果将要输入的为 + - 就直接弹出栈中的操作数
		if(right == '-' || right == '+') return 0;
		//如果将要输入的为 * / 就将其压入
		if(right == '/' || right == '*') return 1;	
	}
	else if (left == '*' || left == '/') return 0;  //这两个运算符最高
	else if (left == '#' || '(') return 1;  //遇到这两个  直接插入
	return -1;
}

/*
   函数名：inToPost
   函数功能：将中缀表达式转换为后缀表达式输出 
   函数参数：中缀表达式，放在字符数组中 
   返回值：无 
*/
void inToPost(char *expression)
{
   //在此处填写代码，完成中缀表达式转换为后缀表达式并输出
   /**********  Begin  **********/
   Stack operationCha = createStack();
   push('#',operationCha);
   for(int i= 0;;i++)
   {
	   if(expression[i]>= '0' && expression[i] <= '9')
	   {
		   while (expression[i]>= '0' && expression[i] <= '9')
		   {
			   cout << expression[i];
			   i++;
		   }
		   //下一个就是运算符 了   -- 避免在第一层循环跳过运算符
		   i--;
		   cout << " ";
		//左括号就直接 压进栈中
	   }else if(expression[i] == '(')
	   {
		   push(expression[i],operationCha);
	   }else if(expression[i]== ')')
	   {
		   while(top(operationCha) != '(')
		   {
			   cout << pop(operationCha) << ' ';
		   }
		   pop(operationCha);
	   }else if(expression[i] == '\0')
	   {
		   while(top(operationCha) != '#')
		   {
			   cout << pop(operationCha);
			   if(top(operationCha) != '#') cout << ' ';
		   }
		   break;
	   }else if(judgeCha(top(operationCha),expression[i]) == 1){
		   push(expression[i],operationCha);
		//不断弹出运算符较高的元素  直到遇到运算符比当前低的元素再压栈 
	   }else if(judgeCha(top(operationCha),expression[i]) == 0)
	   {
		   do
		   {
			   cout << pop(operationCha) << ' ';
		   }while(judgeCha(top(operationCha),expression[i]) == 0);
		   push(expression[i],operationCha);
	   }
	   


   }
   

   
   
   
   /**********  End  **********/
}
#endif
