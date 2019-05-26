#include<stdio.h>
#include<stdlib.h>
int main()
{
void  Charcombine(char* first,char* second);
char c[80],d[80];
gets(c);
gets(d);
Charcombine(c,d);
printf("%s",c);
return 0;
}
void Charcombine(char* first,char*second)
{
	char s[80];
	char* temp=s;
	char* temp2=s;
	char*first2=first;
   printf("%s\n",first2);
    while((*first!='\0')&&(*second!='\0'))
   {if(*first<*second)
    *temp++=*first++;
   else
    *temp++=*second++;
   }
   while((*temp++=*first++)!='\0');
   temp--;//¸²¸Çµô'\0'
   while((*temp++=*second++)!='\0');
   while((*first2++=*temp2++)!='\0');
}
