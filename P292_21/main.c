#include <stdio.h>
#include <stdlib.h>
int count=0;

void sort(int a[])
{
int** p;
int*tm;
tm=a;
p=&tm;
int max=0;
printf("%d\n",*(*p+1));
for(int i=0;i<=count-1;i++)
    {
    max=i;
     for(int j=i;j<count;j++)
     {
         if(*(*p+max)<*(*p+j))
         {
             max=j;
         }
     }
    if(max!=i)
        {
        int t=*(*p+i);
       *(*p+i)=*(*p+max);
        *(*p+max)=t;
        }
    }
for(int i=0;i<=count-1;i++)
       {
           printf("%d,",a[i]);
       }
}
int main()
{

    scanf("%d",&count);
    int num[count];
    for(int i=0;i<=count-1;i++)
       {
           scanf("%d",&num[i]);
       }
    sort(num);
    for(int i=0;i<=count-1;i++)
       {
           printf("%d\n",num[i]);
       }
    return 0;
}
