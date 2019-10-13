#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkStack.h"
#pragma warning(disable:4996)

int main()
{
    LinkStack* ls=LS_Create();
    char dowhat[100];
    while(true) {
        scanf("%s", dowhat);
        if (!strcmp(dowhat,"push")) {
            T x;
            scanf("%d", &x);
            LS_Push(ls,x);
        }else if (!strcmp(dowhat,"pop")) {
            T item;
            LS_Pop(ls, item);
		}
        else {
            break;
        }
    }
    int length=LS_Length(ls);
    printf("Stack length: %d\n", length);
    LS_Print(ls);
    LS_Free(ls);
}
