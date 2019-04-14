#include<stdio.h>
#include<math.h>

int main()
    {
float a,b,result=0.0;
    char op;
    printf("please input:\n");
    scanf("%f %c %f",&a,&op,&b);

    
    switch(op)
    {
        case'+':result=a+b;break;
        case'-':result=a-b;break;
        case'*':result=a*b;break;
        case'/':
        if(fabs(b)>=1e-7)
        {
            result=a/b;
        }
    
		break;
        default:break;
        
    }
    if(result!=0.0)
    {
    printf("%f%c%f=%7.2f",a,op,b,result);
    }
    return 0;}
