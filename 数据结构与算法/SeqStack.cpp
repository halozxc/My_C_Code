/*************************************************************
    date: July 2017
    copyright: Zhu En（祝恩）
    DO NOT distribute this code.
**************************************************************/
//顺序存储的栈 实现文件
/////////////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include "SeqStack.h"

/*创建一个栈*/
SeqStack* SS_Create(int maxlen)
{
	SeqStack* ss=(SeqStack*)malloc(sizeof(SeqStack));
	ss->data=(T*)malloc(maxlen*sizeof(T));
	ss->top=-1;
	ss->max=maxlen;
	return ss;
}

/*释放一个栈*/
void SS_Free(SeqStack* ss)
{
	free(ss->data);
	free(ss);
}

/*清空一个栈*/
void SS_MakeEmpty(SeqStack* ss)
{
	ss->top=-1;
}

/*判断栈是否为满*/
bool SS_IsFull(SeqStack* ss)
{
	/*请在BEGIN和END之间实现你的代码*/
    /*****BEGIN*****/
if(ss->top==ss->max-1){


return true;
}
else
{
    return false;
}

    /******END******/
}

/*判断栈是否为空*/
bool SS_IsEmpty(SeqStack* ss)
{
	/*请在BEGIN和END之间实现你的代码*/
    /*****BEGIN*****/
   if(ss->top==-1){
       return true;
   }
   else
   {
       return false;
   }
   
    /******END******/
}

/*获取栈元素个数*/
int SS_Length(SeqStack* ss)
{
	/*请在BEGIN和END之间实现你的代码*/
    /*****BEGIN*****/
return ss->top+1;
    /******END******/
}

/*将x进栈,满栈则无法进栈(返回false)*/
bool SS_Push(SeqStack* ss, T x)
{
	/*请在BEGIN和END之间实现你的代码*/
    /*****BEGIN*****/
if(SS_IsFull(ss)){
    return false;
}
else
{
   // printf("pusing\n");
    ss->top++;
    ss->data[ss->top]=x;
    return true;
}

    /******END******/
}

/*出栈，出栈的元素放入item,空栈则返回false*/
bool SS_Pop(SeqStack* ss, T &item)
{
	/*请在BEGIN和END之间实现你的代码*/
    /*****BEGIN*****/
if(SS_IsEmpty(ss)){
    return false;

}
else
{
    item=ss->data[ss->top];
    ss->top--;
    return true; 
}

    /******END******/
}

/*获取栈顶元素放入item中,空栈则返回false*/
bool SS_Top(SeqStack* ss, T & item)
{
	if (SS_IsEmpty(ss)) {
		return false;
	}
	item = ss->data[ss->top];
	return true;
}

/*从栈底到栈顶打印出所有元素*/
void SS_Print(SeqStack* ss)
{
	if (SS_IsEmpty(ss)) {
		printf("stack data: Empty!\n");
		return;
	}
	printf("stack data (from bottom to top):");
	int curr=0;
	while(curr<=ss->top) {
		printf(" %d", ss->data[curr]);
		curr++;
	}
	//printf("\n");
}
