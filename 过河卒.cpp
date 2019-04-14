#include<iostream>
using namespace std;
int a,b,c,d;
int tx,ty;
long long result;
int next[2][2]={{1,0},{0,1}};
long long dfs(int x,int y);
 long long dfs(int x,int y)
{   
    
   	if (x==a&&y==b) 
     result=result+1;
     
		
	
	int i;
	for (i =0;i<=1;i++)
	{
	
			
          tx=x+next[i][0];
          ty=y+next[i][1];
 
			if(tx==c&&ty==d||tx==c-1&&ty==d-2||tx==c+1&&ty==d-2||tx==c+2&&ty==d+1||tx==c+2&&ty==d-1||tx==c-1&&ty==d+2||tx==c+1&&ty==d+2||tx==c-2&&ty==d+1||tx==c-2&&ty==d-1||tx>a||ty>b)
			continue;
			else
			{
			
			dfs(tx,ty);
			}
		
		}
	
    return result;
}
int main()
{
    cin>>a;
    cin>>b;
    cin>>c;
    cin>>d;

long long re;
	re=dfs(0,0);
	cout <<re;
	return 0;
	
}
