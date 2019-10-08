/*************************************************************
    date: July 2017
    copyright: Zhu En（祝恩）
    DO NOT distribute this code.
**************************************************************/
// 顺序存储的栈 头文件
///////////////////////////////////////////////////////////////
typedef int T;
struct SeqStack{
    T* data; // 数据元素指针
    int top; // 栈顶元素编号
    int max; // 最大节点数
};

SeqStack* SS_Create(int maxlen);
void SS_Free(SeqStack* ss);
void SS_MakeEmpty(SeqStack* ss);
bool SS_IsFull(SeqStack* ss);
bool SS_IsEmpty(SeqStack* ss);
int SS_Length(SeqStack* ss);
bool SS_Push(SeqStack* ss, T x);
bool SS_Pop(SeqStack* ss, T& item);
bool SS_Top(SeqStack* ss, T& item);
void SS_Print(SeqStack* ss);
