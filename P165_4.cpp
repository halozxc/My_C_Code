#include<stdio.h>
#include<stdlib.h> 
 int* Ainsert(int a[],int x,int l)
{
	l++;
	int* b;
	b=(int *)malloc(sizeof(int)*l);
	for(int i=0,j=0;i<=l-1;i++)
	{
		if(a[i]<=x)
		{
			b[i]=a[j];
        	j++;
    	}
	    else
		{
		b[i]=x;
		}
	}
  return b;
}
int main()
{
	int a[]={1,2,3,4,5,6,7,8,9,10},x;
	int *p=a;
	int l = sizeof(a)/sizeof(int);
    for(int i=0;i<=9;i++)
	printf("%d;",a[i]);
	scanf("%d",&x);
	p=Ainsert(a,x,l);
	for(int i=0;i<=10;i++)
	printf("%d;",*(p+i));
	
}

