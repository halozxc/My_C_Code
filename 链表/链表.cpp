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
	struct stud_node* head, * tail, * p;
	int num;

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
	printf("")
	return  0;
}

