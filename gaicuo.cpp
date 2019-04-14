#include <stdio.h>
int  main()
{	int a;
	float b;
	
	scanf("%d%f",&a,&b);
	
	double c;
	scanf("%.lf",c);
		 
	printf("a=%d,b=%f,c=%lf\n",a,b,c);
	return 0;
}

