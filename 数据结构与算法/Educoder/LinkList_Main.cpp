#include <stdio.h>
#include <stdlib.h>
#include "LinkList.h"
#pragma warning(disable:4996)

int main()
{
    LinkList* llist=LL_Create();
    int i;
    int x;

    int a;
    scanf("%d", &a);
    for(i=0; i<a; i++) {
        scanf("%d",&x);
        LL_InsAfter(llist,x);
    }

    LL_SetPosition(llist, 0);
    scanf("%d", &a);
    for(i=0; i<a; i++) {
        scanf("%d", &x);
        LL_SetPosition(llist,0);
        LL_InsAfter(llist,x);
    }

    // LL_Print(llist);
    scanf("%d", &x);
    LL_DelValue(llist, x);

    scanf("%d", &i);
    LL_SetPosition(llist, i);
    LL_DelAt(llist);

    LL_Print(llist);
    LL_Free(llist);

}
