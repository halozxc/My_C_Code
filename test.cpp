/*
本关任务：随机生成20个从1－100之间的随机数，用递归与分治法编程实现元素的查找算法。
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
int main( void )
{
	int array[101];
    for(int i=0;i<=100;i++){
        array[i]=0;
    }
    int p;
    for (int i=1;i<=5;i++)
    {
        scanf("%d", &p);
        array[p]++;
    }
    int k=0;
    int repeat=-1;
    for(int i =0 ;i<=100;i++){
        if(array[i]>0){
            k += array[i];
            if(k<5){
               printf("%d ",i);
            }
            else{
                printf("%d\n",i);
            }
        }
        if(array[i]>1){
            repeat = i;
        }
      
    }
    if(repeat>0)
    printf("%d", repeat);
    return  0;
}

    


