#include<stdio.h>
#include<stdlib.h>
typedef struct number{
	int id;
	int num;
 number* next;
};
number* create(int a[])
{
	int i=0;

	number*p,*head,*tail;
	head=tail=NULL;
	tail=p=(number*)malloc(sizeof(number));
	head=p;

	p->num=a[0];
	p->id=i;
	while(a[i]>0)
	{
		tail->next=p;
		tail=p;

	i++;
		p=(number*)malloc(sizeof(number));
	   p->num=a[i];
	  p->id=i;
	}

tail->next=NULL;
return head;
}
int searchv(number *x,int a)//ËÑË÷Öµ
{
	while(x->num!=a&&x!=NULL){
	  	x=x->next;

   }
  if(x==NULL){
      	return -1;
  }
  else
  {
  	return x->id;
  }
}
int searchi(number *x,int a)//ËÑË÷id
{
	while(x->id!=a&&x!=NULL){
	  	x=x->next;

   }
  if(x==NULL){
      	return -1;
  }
  else
  {
  	return x->num;
  }
}
number* insertn(number* x, int id){
	int num;
	number *head=x,*p=(number*)malloc(sizeof(number));
	printf("input the numer you want to insert");
	scanf("%d",&num);
	while(x->id<id)
	x=x->next;
	p->id=id+1;
    p->num=num;
    p->next=x->next;
	x->next=p;
		x=x->next->next;
		while(x!=NULL){
		  x->id++;
		  x=x->next;
     }
  return  head;
}
number* deleten(number* p,int id)
{
    number* a=(number*)malloc(sizeof(number));

    a->next=p;
    number* head=a->next;
    for(a;a->next!=NULL;a=a->next,p=p->next)
{
    if(p->id==id)
    {
        a->next=p->next;
       break;
    }
}
return head;
}
int main()
{
int num;
int a[7]={21,3,15,27,11,18,0};
number *p,*head;
head=p=create(a);
for(p;p!=NULL;p=p->next)
printf("%d\n",p->num);
printf("input a number to search");
scanf("%d",&num);
if(searchv(head,num)>=0)
printf("%d\n",searchv(head,num));
printf("input a id to search");
scanf("%d",&num);
if(searchi(head,num)>=0)
printf("%d\n",searchi(head,num));
printf("input a node id you want to insert");
scanf("%d",&num);
head=insertn(head,num);
p=head;
for(p;p!=NULL;p=p->next)
printf("%d\n",p->num);
printf("input the node id to delete");
scanf("%d",&num);
p=head;
p=deleten(p,num);
for(p;p!=NULL;p=p->next)
printf("%d\n",p->num);
return 0;
}
