#include<iostream>
int main(){
	int n;
	std::cin>>n;
	int a[n][n];
	int count =1;
	int x=0,y=0;
	int dx=1,dy=0;
  	 for(int i= 0;i<=n-1;i++){
    	for(int j =0;j<=n-1;j++)
         a[i][j]=0;
	}
	  while(count<=n*n){
      if(dx==0&&dy==-1){
      	if(a[x+dx][y+dy]!=0){
      		dx=1;
      		dy=0;
      		x=x+dx;
      		y=y+dy;
      		a[x][y]=count;
			  count=count+1;
		 
		  }
      else{
      	x=x+dx;
      	y=y+dy;
     a[x][y]=count;
	 	count=count+1;
	  }
	   }
	  if(dx==0&&dy==1){
      	if(a[x+dx][y+dy]!=0){
      		dx=-1;
      		dy=0;
      		x=x+dx;
      		y=y+dy;
      		a[x][y]=count;
			  count=count+1;
		  }
		  else{
		  	x=x+dx;
      		y=y+dy;
      		a[x][y]=count;
			  count=count+1;
		  }
       }		
	 if(dx==1&&dy==0){
      	if(a[x+dx][y+dy]!=0){
      		dx=0;
      		dy=1;
      		x=x+dx;
      		y=y+dy;
      		a[x][y]=count;
			  count=count+1;
		  }
		  else{
		  	x=x+dx;
      		y=y+dy;
      		a[x][y]=count;
			  count=count+1;
		  }
       }		
	 if(dx==-1&&dy==0){
      	if(a[x+dx][y+dy]!=0){
      		dx=0;
      		dy=-1;
      		x=x+dx;
      		y=y+dy;
      		a[x][y]=count;
			  count=count+1;
		  }
		  else{
		  	x=x+dx;
      		y=y+dy;
      	a[x][y]=count;
		  	count=count+1;
		  }
       }		
	}
    for(int i= 0;i<=n-1;i++){
    	for(int j =0;j<=n-1;j++)
    	std::cout<<a[i][j]<<" ";
    	std::cout<<std::endl;
	}
	return 0;
}
