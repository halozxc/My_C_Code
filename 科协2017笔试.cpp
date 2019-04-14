
#include<iostream>
void func(int i, int number[], int _number)
{
	if (i==9)
	{
		number[i] = _number;
		return;
	}
	else
	{
		number[i] = _number;
	    
		func(++i, number,_number+=2);
	}
}
int main()
{
	int number[10];
	func(0, number, 20);
	for (int i = 0; i < 10; ++i)
		printf("%d\t", number[i]);
	return 0;
}
