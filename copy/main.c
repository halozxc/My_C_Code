#include <stdio.h>
#include <stdlib.h>
#include<string.h>
void Vcopy(char* a,char* b,int p)
{
    b+=p;
    while((*a++=*b++)!='\0');
}
int main()
{
    char a[80];
    char b[80];
    int p;

    gets(b);
    scanf("%d",&p);
    Vcopy(a,b,p);
   printf("%s",a);

}
