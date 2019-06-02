#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stud_node
{
	int num;
    struct stud_node* next;
};
int main()
{
	struct stud_node* head, * tail, * p *key;
	int num;
    int Foption,n;
	int size = sizeof(struct stud_node);
	head = tail = NULL;
	printf("input num:\n");
	scanf("%d", &num);
		p = (struct stud_node*)malloc(size);
	tail=p;
	int count=1;
	while (num != 0)
	{
	    if (count ==1) {
			head = p;
		}

	    p->num = num;
		p->next = NULL;
		tail->next = p;
		tail = p;
		p = (struct stud_node*)malloc(size);
	    printf("input num:\n");
		scanf("%d", &num);
	    count++;
	}
	p->next=NULL;
	tail->next=p;
	tail=p;
	for (p = head; p->next!= NULL; p = p->next)
		printf("%d\n", p->num);
	printf("输入1来查找节点，输入2来插入节点，输入3来删除节点");
	scanf("%d",&Foption);
	key=head;
	switch(Foption ){
    case 1:
        printf("输入n来查找第n个节点");
        scanf("%d",n);
        count=1;
        while(count!=n){
          key=head->next;
          count++;
        }
	  printf("%d",key->num);
	  break;
	case 2:

	}

	return  0;
}
