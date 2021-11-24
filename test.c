#include<stdio.h>
int main()
{
int t,i=0,x,y,flag;
scanf("%d",&t);
char a[100]="",b[t];
while(t-->0){
scanf("%s",a);
x=strlen(a);
flag=0,y=0;
while(y<=x/2){
if(a[y]!=a[x-y-1])flag=1;
y++;}
if(flag)b[i++]='1';
else b[i++]='0';}
x=-1;
while(++x<i){
if(b[x]=='0')printf("Nope\n");
else printf("Yes\n");}
return 0;}
