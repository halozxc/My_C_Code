#include <stdio.h>
void fun(int  a, int  b, long  *c)
{
	int i,j,m,n;
	i=a%10;j=a%100,j/=10;
	m=b%10;n=b%100,n/=10;
*c=(i*1000)+(m*100)+(j*10)+(n);
}
int main()
{  int  a,b; long  c;void NONO ();
   printf("Input a, b:");
   scanf("%d%d", &a, &b);
   fun(a, b, &c);
   printf("The result is: %ld\n", c);
   NONO();
}
void NONO ()
{/* 本函数用于打开文件，输入数据，调用函数，输出数据，关闭文件。 */
  FILE *rf, *wf ;
  int i, a,b ; long c ;

  rf = fopen("in.dat","r") ;
  wf = fopen("out.dat","w") ;
  for(i = 0 ; i < 10 ; i++) {
    fscanf(rf, "%d,%d", &a, &b) ;
    fun(a, b, &c) ;
    fprintf(wf, "a=%d,b=%d,c=%ld\n", a, b, c) ;
  }
  fclose(rf) ;
  fclose(wf) ;
}
