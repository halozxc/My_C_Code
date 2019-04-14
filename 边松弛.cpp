#include<iostream>
using namespace std;
int main()
{
    int n,l;
    cin>>n>>l;
    int dis[n+1][n+1];
    int i,j,x,y,t;
    for(i =0;i<=n;i++)
     {
	   if(i!=j)
	   for (j=0;j<=n;j++) 
       dis[i][j]=99999;
     else
      dis[i][j]=0; 
   }
    dis[1][1]=0;
	for(i =1;i<=l;i++)
	{
	cin>>x>>y>>t;
	dis[x][y]=t;
}
	int pb[n+1];
	for(i=1;i<=n;i++)
	pb[i]=dis[1][i];
	int book[n+1] ;
  for(i=0;i<=n;i++)
  book[i]=0;

	book[1]=1;
	int min,p;//p是用来指出循环后路径最短的那个城市 
     min =99999;
	for (i=2;i<=n;i++)
	{
		for(j=2;j<=n;j++) 
		{
			if (book[j]==0&&pb[j]<min)
		    {
			min = pb[j];
			p=j;
	         }
		}
	  book[p]=1;
	   min=99999;
	   for(j=1;j<=n;j++)
	   if (dis[p][j]+pb[p]<dis[1][j]&&dis[p][j]<99999)
	   pb[j]=dis[p][j]+pb[p];
	}
	for(i=1;i<=n;i++)
	cout <<pb[i]<<endl;
	return 0;
	 
 } 
