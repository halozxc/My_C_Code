#include <stdio.h>
#define N 6
int main()
{  
int i,j,x,n;
int array[N+1]={1,3,6,7,8,9};
    printf("please input search x:");
    scanf("%d",&x);
    i=0;
    n=N;
    while(array[i]<x)
    {
         i++;
    }
    if(i>=n)
{
      array[i]=x;
      n++;
}
else if(x==array[i]) //ÕÒµ½£¬ÔòÉ¾³ı
    {   for(j=i;j<n ;j++)
{
       array[j]=array[j+1]   ;
}
n--;
}
else
{
{ for(j=n-1;j>=i;j--)
  {
        array[j+1]=array[j]   ;
  }
}
array[i]=x;
   n++   ;
}
for(i=0;i<n;i++)
{ printf("%d,",array[i]);}
printf("\n");
return 0;
}
