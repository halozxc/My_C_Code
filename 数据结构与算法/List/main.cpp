#include <iostream>

using namespace std;
int a[11]={0};//???????????????

int insert(int position ,int value)//????
{
   int i;
   if(position>10)
   {
    cout<<"????��????��"<<endl;
    return 0;
    }
    else
    {
        for(i=9;i>(position-1);i--)
        {
            a[i]=a[i-1];
        }
    a[i]=value;
    return 1;
    }
}
void print(){//????????
 for(int i=0;i<=9;i++)
 {
     cout<<a[i]<<";";
 }
      cout<<endl;
}
int mydelete(int position)
{
    if(position<0||position>10)
    {
        cout<<"???��????��"<<endl;
        return 0;
    }
  else{
    for(int i=position-1;i<10;i++)
    {
        a[i]=a[i+1];
    }
   return 0;
  }

}

int main()
{

 cout<<"??????????6??????"<<endl;
 for(int i=0;i<6;i++)
    {
    cin>>a[i];

    }
    print();
    cout<<"?????4???????"<<endl;
cout<<"??��???????????0"<<endl;
if(insert(3,0))//????????????
{

    print();1
}
    cout<<"??��??11?????????"<<endl;
    if(insert(11,5))//????????????
{

    print();
}
    if(mydelete(2))
    {
        print();
    }
    return 0;
}
