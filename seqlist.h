/*************************************************************
    date: April 2017
    copyright: Zhu En
    DO NOT distribute this code without my permission
**************************************************************/
// 顺序表头文件
//////////////////////////////////////////////////////////
#if !defined(Seqlist__CIELSI_989SE_AJIEZN_728JULC__INCLUDED_)
#define Seqlist__CIELSI_989SE_AJIEZN_728JULC__INCLUDED_
//////////////////////////////////////////////////////////
typedef int T; // 数据元素的数据类型
struct SeqList{
	T* data; // 数据元素的开始地址
	int len;  // 当前长度
	int max; // 线性表的最大长度
};


//declaration of functions:
SeqList* SL_Create(int max);
void SL_Free(SeqList* slist);
void SL_MakeEmpty(SeqList* slist);
int SL_Length(SeqList* slist);
bool SL_IsEmpty(SeqList* slist);
bool SL_IsFull(SeqList* slist);
T SL_GetAt(SeqList* slist, int i);
void SL_SetAt(SeqList* slist, int i, T x);
bool SL_InsAt(SeqList* slist, int i, T x);
T SL_DelAt(SeqList* slist, int i);

int SL_FindValue(SeqList* slist, T x);
int SL_DelValue(SeqList* slist, T x);

void SL_Print(SeqList* slist);
///////////////////////////////////////////////////////////
#endif //Seqlist__CIELSI_989SE_AJIEZN_728JULC__INCLUDED_
