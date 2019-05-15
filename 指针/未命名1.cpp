#include<stdio.h>
#include<stdlib.h>
int a[3][3];
void Matrix_Transpose(){
	int i,j,temp;
	for(i=0;i<=2;i++){
		for(j=i;j<=2;j++){
            temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
		}
    }
}
int main()
{
a[3][3]; //={{1,2,3},{4,5,6},{7,8,9}};
int k=0;
for(int i=0; i<3; i++)
	for(int j=0;j<3;j++)
		a[i][j]=++k;
	Matrix_Transpose();
for(int i=0; i<3; i++)
	for(int j=0;j<3;j++)
	printf("%d\n",a[i][j]);
	return 0;
}

