#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
typedef struct stud_node
{
	int num;
    struct stud_node* next;
};
stud_node* create(int count){
		struct stud_node* head, * tail, * p;
	int num;
    int size = sizeof(struct stud_node);
	head = tail = NULL;

	num=1;
		p = (struct stud_node*)malloc(size);
	tail=p;
	
	while (num<count)
	{
	    if (num ==1) {
			head = p;
		}
	  
	    p->num = num;
		p->next = NULL;
		tail->next = p;
		tail = p;
		p = (struct stud_node*)malloc(size);
	    
		num++;
	}
	p->next=NULL;
	tail->next=head;
	tail=p;
return head;
printf("successful");
}
void delate(stud_node *a,stud_node *b,stud_node *c)
{
 a->next=c;
b=c;
c=c->next;

}
int main()
{
int count =1;
stud_node *mynode=create(13);
	stud_node*now,*next,*last;
	now=mynode->next;
	next=mynode->next->next;
	last=mynode;
while(now->next!=now){
	count++;
	if(count==3)
	{
		count=0;
	    delate(last,now,next);
	}
    else{
    	last=now;
		now=next;
		next=next->next; 
   }
//printf("%d",now->num);
	
}
printf("%d",now->num);
}
