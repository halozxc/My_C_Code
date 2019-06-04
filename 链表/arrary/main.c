#include<stdio.h>
int main()
{
	int b[][3]={1,2,3,4};
	int a[][3]={{1},{2},{3}};
	int c[2][3]={{1,2},{3,4},{5,6}};
	//printf("%d\n",a[0][1]);
	//printf("%d\n",b[1][0]);
   for(int i=0;i<=2;i++)
    for(int j=0;j<=3;j++)
    printf("%d\n",c[i][j]);


}
