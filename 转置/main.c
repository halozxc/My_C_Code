#include<stdio.h>
#include<stdlib.h>
void Matrix_Transpose(int a[3][3]){
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
int a[3][3]={{1,2,3},{4,5,6},{7,8,9}};
	Matrix_Transpose(a);
	for(int i=0;i<3;i++)
    for(int j=0;j<=2;j++)
    printf("%d",a[i][j]);

	return 0;
}
