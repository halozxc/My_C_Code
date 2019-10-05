#include<stdio.h>
#include<stdlib.h>
struct product;
typedef struct product *PNode；
struct product
{
   char productName[20]; //产品名
   int saleAmount ;//销量
   struct product *link;//下一个节点
} ;
struct linkQueue_product{
    PNode h;//队列头
    PNode t;//队列尾
};
typedef struct linkQueue_product *Plinkqueue;
PlinkQueue createEmptyQueue_link(void)
{
   Plinkqueue x;
   x=(Plinkqueue)malloc(sizeof(struct Plinkqueue));
   x->h=null;
   x->t=null;
   return x;
}



int main()
{
createEmptyQueue_link();
return 0;
}