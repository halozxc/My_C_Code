#include<stdio.h>
int main()
  {
	   int martix[5][5]={{17,24,1,8,15},{23,5,7,14,16},{4,6,13,20,22},{10,12,19,21,3},{11,18,25,2,9}};
	   int sum1=0;
	   int sum2=0;
	   int sum3=0;
	   bool ismagic =true;
	  // for(int i =0;i<=4;i++)
	  // for(int j =0;j<=4;j++)
	   //{
	   	 //printf("请输入%d行%d列的数字\n",i+1,j+1);
		 //scanf("%d",&martix[i][j]);
	   //}
	   	
	   for(int i=0,j=0;i<=4;i++,j++)
	   sum1+=martix[i][i];
	   
	   	   for(int i=0,j=4;i<=4;i++,j--)
	   sum2+=martix[i][j];
		 
		if(sum1==sum2)
		{
	 		for(int i=0,j=0;i<=4;i++)
			{
			    sum3=0;
				for(j=0;j<=4;j++)
 	             	sum3+=martix[i][j];
	            if(sum3!=sum1)
				ismagic =false;
				break;
			}
		    for(int i=0,j=0;j<=4;j++)
			{
			    sum3=0;
				for(i=0;i<=4;i++)
 	             	sum3+=martix[i][j];
	            if(sum3!=sum1)
				ismagic =false;
				break;
			}
		}	
	   
	   else{
	   	ismagic =false;
	   }
	    if(ismagic)
		{
	    	for(int i =0;i<=4;i++){
			
		   for(int j =0;j<=4;j++)
		   {
		   	 printf("%d    ",martix[i][j]);
			
		   }	
		printf("\n");
		}
		} 
	}
    
