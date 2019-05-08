#include <stdio.h> 
void mystrc(char* s,char* t);
int main()
{
char s[80],t[80];
gets(s);  
gets(t);
mystrc(s,t);
puts(t);
return  0;
}
void mystrc(char* s,char* t)
{
while(*t != 0) t++;
while((*t++=*s++)!='\0');
}

