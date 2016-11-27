#include <stdio.h>

int fib(int n)
{
	if(n<=1)
		return n;
	int f1=0,f2=1,f,i;
	
	for(i=2;i<=n;i++)
	{
		f=f1+f2;
		f1=f2;
		f2=f;
	}

	return f;
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