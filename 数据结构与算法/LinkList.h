/*************************************************************
    date: June 2017
    copyright: Zhu En
    DO NOT distribute this code without my permission.
**************************************************************/
// 单链表 头文件
///////////////////////////////////////////////////
#if !defined(LINKED_LIST_H_LIELJE7398CNHD_INCLUDE_)
#define LINKED_LIST_H_LIELJE7398CNHD_INCLUDE_
////////////////////////////////////////////////////
 
typedef int T;
struct LinkNode {
    T data;
    LinkNode* next;
};
struct LinkList {
    LinkNode* front;  // 指向头结点
    LinkNode* rear;   // 指向尾结点
    LinkNode* pre;    // 指向当前位置结点的前一个结点
    LinkNode* curr;   // 指向当前位置结点
    int position;     // 当前位子结点的编号
    int len;          // 线性表的大小（链表结点数）
};

// 1）	
LinkList* LL_Create();
// 创建一个链接存储的线性表，初始为空表，返回llist指针。

// 2）	
void LL_Free(LinkList* llist);
// 释放链表的结点，然后释放llist所指向的结构。

// 3）	
void LL_MakeEmpty(LinkList* llist);
// 将当前线性表变为一个空表，因此需要释放所有结点。

// 4）	
int LL_Length(LinkList* llist);
// 返回线性表的当前长度。

// 5）	
bool LL_IsEmpty(LinkList* llist);
// 若当前线性表是空表，则返回true，否则返回TRUE。

// 6）  
bool LL_SetPosition(LinkList* llist, int i);
// 设置线性表的当前位置为i号位置。
// 设置成功，则返回true，否则返回false（线性表为空，或i不在有效的返回）
// 假设线性表当前长度为len，那么i的有效范围为[0,len]

// 7)		
int LL_GetPosition(LinkList* llist);
// 获取线性表的当前位置结点的编号

// 8）	
bool LL_NextPosition(LinkList* llist);
// 设置线性表的当前位置的下一个位置为当前位置。
// 设置成功，则返回true，否则返回false（线性表为空，或当前位置为表尾）

// 9）	
T LL_GetAt(LinkList* llist);
// 返回线性表的当前位置的数据元素的值。

// 10）	
void LL_SetAt(LinkList* llist, T x);
// 将线性表的当前位置的数据元素的值修改为x。

// 11）	
bool LL_InsAt(LinkList* llist, T x);
// 在线性表的当前位置之前插入数据元素x。空表允许插入。当前位置指针将指向新结点。
// 若插入失败，返回false，否则返回true。

// 12）	
bool LL_InsAfter(LinkList* llist, T x);
// 在线性表的当前位置之后插入数据元素x。空表允许插入。当前位置指针将指向新结点。
// 若插入失败，返回false，否则返回true。

// 13）	
bool LL_DelAt(LinkList* llist);
// 删除线性表的当前位置的数据元素结点。
// 若删除失败（为空表），则返回false，否则返回true。

// 14）	
bool LL_DelAfter(LinkList* llist);
// 删除线性表的当前位置的后面那个数据元素。
// 若删除失败（为空表，或当前位置时表尾），则返回false，否则返回true。

// 15）	
int LL_FindValue(LinkList* llist, T x);
// 找到线性表中第一个值为x的数据元素的编号。
// 返回值-1表示没有找到，返回值>=0表示编号。

// 16）	
int LL_DelValue(LinkList* llist, T x);
// 删除第一个值为x的数据元素，返回该数据元素的编号。如果不存在值为x的数据元素，则返回-1.

// 17）	
void LL_Print(LinkList* llist);
// 打印整个线性表。

#endif // LINKED_LIST_H_LIELJE7398CNHD_INCLUDE_
