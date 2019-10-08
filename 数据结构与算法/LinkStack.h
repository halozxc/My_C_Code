/*************************************************************
    date: July 2017
    copyright: Zhu En（祝恩）
    DO NOT distribute this code.
**************************************************************/
// 栈的链接存储 头文件
////////////////////////////////////////
#if !defined(LINKED_STACK_H_985552)
#define LINKED_STACK_H_985552
typedef int T; //数据元素类型
struct LNode {
    T data;
    LNode* next;
};

struct LinkStack {
    LNode* top; // 栈顶指针
    int len; // 栈的长度
};

////////////////////////////////////////////
LinkStack* LS_Create();
void LS_Free(LinkStack* ls);
void LS_MakeEmpty(LinkStack* ls);
bool LS_IsEmpty(LinkStack* ls);
int LS_Length(LinkStack* ls);
void LS_Push(LinkStack* ls, T x);
bool LS_Pop(LinkStack* ls, T& item);
bool LS_Top(LinkStack* ls, T& item);
void LS_Print(LinkStack* ls);
#endif
//////////////////////////////////////////
