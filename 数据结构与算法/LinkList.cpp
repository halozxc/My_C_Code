/*************************************************************
    date: June 2017
    copyright: Zhu En
    DO NOT distribute this code without my permission.
**************************************************************/
// 单链表实现文件

#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"

// 1）
LinkList* LL_Create()
// 创建一个链接存储的线性表，初始为空表，返回llist指针。
{
    LinkList* llist=(LinkList*)malloc(sizeof(LinkList));
    llist->front=NULL;
    llist->rear=NULL;
    llist->pre=NULL;
    llist->curr=NULL;
    llist->position=0;
    llist->len=0;
    return llist;
}

// 2）	
void LL_Free(LinkList* llist)
// 释放链表的结点，然后释放llist所指向的结构。
{
    LinkNode* node=llist->front;
    LinkNode* nextnode;
    while(node){
        nextnode=node->next;
        free(node);
        node=nextnode;
    }
    free(llist);
}

// 3）	
void LL_MakeEmpty(LinkList* llist)
// 将当前线性表变为一个空表，因此需要释放所有结点。
{
    LinkNode* node=llist->front;
    LinkNode* nextnode;
    while(node){
        nextnode=node->next;
        free(node);
        node=nextnode;
    }
    llist->front=NULL;
    llist->rear=NULL;
    llist->pre=NULL;
    llist->curr=NULL;
    llist->position=0;
    llist->len=0;
}

// 4）	
int LL_Length(LinkList* llist)
// 返回线性表的当前长度。
{
    return llist->len;
}

// 5）	
bool LL_IsEmpty(LinkList* llist)
// 若当前线性表是空表，则返回true，否则返回TRUE。
{
    return llist->len==0;
}

// 6）  
bool LL_SetPosition(LinkList* llist, int i)
// 设置线性表的当前位置为i号位置。
// 设置成功，则返回true，否则返回false（线性表为空，或i不在有效的返回）
// 假设线性表当前长度为len，那么i的有效范围为[0,len]
{	
    int k;
    /* 若链表为空，则返回*/
    if (llist->len==0) return false;

    /*若位置越界*/
    if( i < 0 || i > llist->len)
    {	printf("LL_SetPosition(): position error");
        return false;
    }

    /* 寻找对应结点*/
    llist->curr = llist->front;
    llist->pre = NULL;
    llist->position = 0;
    for ( k = 0; k < i; k++)	{
        llist->position++;
        llist->pre = llist->curr;
        llist->curr = (llist->curr)->next;
    }
    
    /* 返回当前结点位置*/
    return true;
}

// 7)	
int LL_GetPosition(LinkList* llist)
// 获取线性表的当前位置结点的编号
{
    return llist->position;
}

// 8）	
bool LL_NextPosition(LinkList* llist)
// 设置线性表的当前位置的下一个位置为当前位置。
// 设置成功，则返回true，否则返回false（线性表为空，或当前位置为表尾）
{
    if (llist->position >= 0 && llist->position < llist->len)
    /* 若当前结点存在，则将其后继结点设置为当前结点*/
    {
        llist->position++;
        llist->pre = llist->curr;
        llist->curr = llist->curr->next;
        return true;
    }
    else 
        return false;
}

// 9）	
T LL_GetAt(LinkList* llist)
// 返回线性表的当前位置的数据元素的值。
{
    if(llist->curr==NULL)
    {
        printf("LL_GetAt(): Empty list, or End of the List.\n");
        LL_Free(llist);
        exit(1);
	}
    return llist->curr->data;
}

// 10）	
void LL_SetAt(LinkList* llist, T x)
// 将线性表的当前位置的数据元素的值修改为x。
{
    if(llist->curr==NULL)
    {
        printf("LL_SetAt(): Empty list, or End of the List.\n");
        LL_Free(llist);
        exit(1);
    }
    llist->curr->data=x;
}

// 11）	
bool LL_InsAt(LinkList* llist, T x)
// 在线性表的当前位置之前插入数据元素x。当前位置指针指向新数据元素结点。
// 若插入失败，返回false，否则返回true。
{	
    LinkNode *newNode=(LinkNode*)malloc(sizeof(LinkNode));
    if (newNode==NULL) return false;

    newNode->data=x;

    if (llist->len==0){
        /* 在空表中插入*/
        newNode->next=NULL;
        llist->front = llist->rear = newNode;
	}
    //当前位置为表头
    else if (llist->pre==NULL)
    {
        /* 在表头结点处插入*/
        newNode->next = llist->front;
        llist->front = newNode;
    }
    else {  
        /* 在链表的中间位置或表尾后的位置插入*/
        newNode->next = llist->curr;
        llist->pre->next=newNode;
    }
    //插入在表尾后
    if (llist->pre==llist->rear)
        llist->rear=newNode;
    /* 增加链表的大小*/
    llist->len++;
    /* 新插入的结点为当前结点*/
    llist->curr = newNode;
    return true;
}

// 12）	
bool LL_InsAfter(LinkList* llist, T x)
// 在线性表的当前位置之后插入数据元素x。空表允许插入。当前位置指针将指向新结点。
// 若插入失败，返回false，否则返回true。
{
    // 请在这里补充代码，完成本关任务
    /********** Begin *********/
 if(LL_NextPosition(llist)){
     return LL_InsAt(llist,x);
 }
 else if(llist->len>0){
      printf("rear insert\n");
      LinkNode *newNode=(LinkNode*)malloc(sizeof(LinkNode));
      newNode->data=x;
      newNode->next=NULL;
      llist->rear->next=newNode;
       llist->rear=newNode;
      llist->len++;
      LL_NextPosition(llist);
      return true;
 }
 else
 {
     return LL_InsAt(llist,x);
 }
 

 
 

    /********** End **********/
}

// 13）	
bool LL_DelAt(LinkList* llist)
// 删除线性表的当前位置的数据元素结点。
// 若删除失败（为空表，或当前位置为尾结点之后），则返回false，否则返回true。
{	
    LinkNode *oldNode;
    /* 若表为空或已到表尾之后，则给出错误提示并返回*/
    if (llist->curr==NULL)
    {	
        printf("LL_DelAt(): delete a node that does not exist.\n");
        return false;
    }
    oldNode=llist->curr;
    /* 删除的是表头结点*/
    if (llist->pre==NULL)
    {	
        llist->front = oldNode->next;
    }
    /* 删除的是表中或表尾结点*/
    else if(llist->curr!=NULL){
        llist->pre->next = oldNode->next;
    }
    if (oldNode == llist->rear)	{
        /* 删除的是表尾结点，则修改表尾指针和当前结点位置值*/
        llist->rear = llist->pre;
    }

    /* 后继结点作为新的当前结点*/
    llist->curr = oldNode->next;

    /* 释放原当前结点*/
    free(oldNode);

    /* 链表大小减*/
    llist->len--;
    return true;
}

// 14）	
bool LL_DelAfter(LinkList* llist)
// 删除线性表的当前位置的后面那个数据元素。
// 若删除失败（为空表，或当前位置时表尾），则返回false，否则返回true。
{
    LinkNode *oldNode;
    /* 若表为空或已到表尾，则给出错误提示并返回*/
    if (llist->curr==NULL || llist->curr== llist->rear)
    {
        printf("LL_DelAfter():  delete a node that does not exist.\n");
        return false;
    }
    /* 保存被删除结点的指针并从链表中删除该结点*/
    oldNode = llist->curr->next;
    llist->curr->next=oldNode->next;
    
    if (oldNode == llist->rear)
        /* 删除的是表尾结点*/
        llist->rear = llist->curr;
    /* 释放被删除结点*/
    free(oldNode);
    /* 链表大小减*/
    llist->len --;
    return true;
}

// 15）	
int LL_FindValue(LinkList* llist, T x)
// 找到线性表中第一个值为x的数据元素的编号。
// 返回值-1表示没有找到，返回值>=0表示编号。
{
    LinkNode* p=llist->front;
    int idx=0;
    while(p!=NULL && p->data!=x) {
        idx++;
        p = p->next;
    }
    if (idx>=llist->len) return -1;
    else return idx;
}

// 16）	
int LL_DelValue(LinkList* llist, T x)
// 删除第一个值为x的数据元素，返回该数据元素的编号。如果不存在值为x的数据元素，则返回-1.
{
    int idx=LL_FindValue(llist, x);
    if (idx<0) return -1;
    LL_SetPosition(llist, idx);
    LL_DelAt(llist);
    return idx;
}

// 17）	
void LL_Print(LinkList* llist)
// 打印整个线性表。
{
    LinkNode* node=llist->front;
    while (node) {
        printf("%d ", node->data);
        node=node->next;
    }
    printf("\n");
}
