#include<stdio.h>
#include<stdlib.h>


struct product
{
   char productName[20]; //产品名
   int saleAmount ;//销量
  //下一个节点
} ;
typedef struct Node
{
  struct product info;
  Node *next;
};
typedef Node *PNode;
struct linkQueue_product{
    PNode h;//队列头
    PNode t;//队列尾
};
typedef struct linkQueue_product Plinkqueue;
Plinkqueue createEmptyQueue_link()
{
   Plinkqueue x;
   x.h=NULL;
   x.t=NULL;
   return x;
}
int isEmptyQueue_link(Plinkqueue x)//判断队列是否为空
{
   return (x.h==NULL);

}
void insert_queue(Plinkqueue x,product T)//入队
{
   PNode p=(PNode)malloc(sizeof(struct product));
   p->info=T;
   p->next=NULL;
   if(x.h==NULL){
      x.h=p;
   }
   else{
      x.h->next=p;
   }
  x.t=p;
}
void delete_queue(Plinkqueue x)//入队
{
  if(x.h==x.p==NULL)
  printf("删光了已经\n");
else{
  PNode p=x.h;
   x.h=x.h->next;
   free(p);
}
}
void invert(Plinkqueue q)//翻转
{
   product e;
   if(!isEmptyQueue_link(q))
   {
      e=q.h->info;
      delete_queue(q);
      invert(q)
      insert_queue(q,e);
   }
}
int main()
{
Plinkqueue x=createEmptyQueue_link();//新建空队列
//添加数据到队列中
invert(x);//元素反转
PNode p=x.h;
while(p!=x.t)//输出结果
{
   putchar(p->info.productName+"\n");
   p=p->next
}
 putchar(p->info.productName+"\n");
return 0;
}
