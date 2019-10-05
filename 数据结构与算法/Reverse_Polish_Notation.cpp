//Reverse Polish Notation
#include<iostream>
#include<vector>
#include<string>

using namespace std;
typedef struct op{
       char x;
       int level;//等急越高运算优先级越高
};
class Polynomial{
    string expression;
    int value;
    private:
    int cal(string x){
        for(int i=0;i<x.length,i++)
        {
            printf("hhaha");
        }
    }

    public:
    void set_op(string x){
      expression=x;
    }
    int getvalue(){
        return value;
    }
};

