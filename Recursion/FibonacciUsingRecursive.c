#include <stdio.h>

int fib(int n)
{
	if(n<=1)
		return n;
	
	int f1=fib(n-1);
	int f2=fib(n-2);

	return f1+f2;
}

int main()
{
	int num,result;
	printf("Enter a number to calculate fibbonacci number : ");
	scanf("%d",&num);
	result=fib(num);
	printf("Fibnacci Number of %d = %d\n",num,result);

	return 0;
}