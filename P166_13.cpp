#include<stdio.h>
#include<stdlib.h>
int main()
{
char* Charlink(char* first,char* second);
char c[]="hahhahha",d[]="asdasdsads";

 Charlink(c,d);
printf("%s",c);
return 0;
}
void Charlink(char* first,char*second)
{
	char* temp=first;
	while(*first)
	      first++;
    while((*first++ = *second++)!='\0');
    \*return temp;*/
}
