#include<iostream>
using namespace std;
int main()
{
	struct line
	{
		int data[1000];
		int head; 
        int tail;
	};
   struct table
   {
   	int data[1000];
   	int top;
   };
  struct line x,y;  //两位玩家 
  struct table s; // 这是桌子
 x.head=1;x.tail=1;
 y.head=1;y.tail=1;
 s.top = 0;
 cout<<"enter player one number"<<endl;
 int i =1;
 for(i=1;i<=6;i++)
  {
   cin>> x.data[x.tail];
  x.tail++;
  }
  cout<<"now is player two"<<endl;
  for(i=1;i<=6;i++)
  {
   cin>> y.data[y.tail];
   y.tail++;
  }
  int book[100] ;
  for(i=0;i<=100;i++)
  book[i]=0;


while (x.head<x.tail&&y.head<y.tail)
{

  
  	if (book[x.data[x.head]]>0)
  	 {
		 for (i=book[x.head];i<=s.top; i++)
  	  {
  	  	x.tail++;
  	  	x.data[x.tail]=s.data[i];
		}
        s.top =book[x.head]-1;
	  book[x.data[x.head]] =0;//清除标记 
	   cout<<"x tail="<<x.tail;
	   
		 
     }
	    else
  	 { s.top++;s.data[s.top]=x.data[x.head]; book[x.data[x.head]]=s.top ;x.head++;cout<<"x head="<<x.head;}//把玩家一的牌子加到桌子上 

  
  	if (book[y.data[y.head]]>0)
  	 {
		 for (i=book[y.head];i<=s.top; i++)
  	  {
  	  	y.tail++;
  	  	y.data[y.tail]=s.data[i];
		}
        s.top =book[y.head]-1;
	   book[y.data[y.head]]=0;
	    cout<<"y tail="<<y.tail;
    }
	    else
  	 { s.top++;s.data[s.top]=y.data[y.head]; book[y.data[y.head]]=s.top ;y.head++; cout<<"y head="<<y.head;}//把玩家一的牌子加到桌子上 
}
 if(x.head=x.tail)
 {
   cout<< "玩家1 win，且他的数字是：";
  for (i=x.head;i<=x.tail;i++)
  cout<<x.data[i];
}
  
  else
 {
   cout<< "y win";
 cout<< "玩家2 win，且他的数字是：";
  for (i=y.head;i<=y.tail;i++)
  cout<<y.data[i] ;
}
return 0;

 } 
  
