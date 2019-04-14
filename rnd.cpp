#include<stdio.h>
#include<stdlib.h>//标准(std)操作库(lib), 内含srand(),rand()函数
#include<time.h>//时间库(time), 内含time()系统时间函数int GetRand()//产生随机数的函数
int GetRand(){
//通过系统时间初始化随机数种子//如果不设置随机数种子,则每次rand()函数的起始值都一样.

int n = rand()%181+20 ;// rand()为随机数函数, 产生[0,int型最大值)之间的整数数, 此值依系统不同而不同, 一般为2147483648, 可认为无穷// 通过rand()%181+20转化为[20,200]之间的整数 (注:rand()%181产生[0,180]之间的整数)
return n ; //返回这个整数
}
int main() //主函数
{
for(int i;i<=8;i++){


printf("%d",GetRand()) ; //输出一个随机数
}
}//希望对你有帮助
