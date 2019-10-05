#include <stdio.h>
#include <stdlib.h>
#include "Seqlist.h"
#pragma warning(disable:4996)

int main()
{
	int max=100;
	SeqList* slist=SL_Create(max);
	int n;

	// printf("how many items:");
	scanf("%d", &n);
	int i;
	int item;

	// printf("the items:");
	for (i=0; i<n; i++){
		scanf("%d", &item);
		//printf("%d\n", item);
        SL_InsAt(slist, i, item);
	}
	int idel;

	// printf("delete #:");
	scanf("%d", &idel);
	SL_DelAt(slist, idel);

	// printf("delete a value:");		
	int itemdel;
	scanf("%d", &itemdel);
	SL_DelValue(slist, itemdel);
	SL_Print(slist);
	
	SL_Free(slist);
}