#include <stdio.h>

int factorial(int n)
{
	printf("I am Calculating : %d!\n",n);
	
	if(n==0)
		return 1;
	
	int f=n*factorial(n-1);
	printf("I have calculated %d! = %d\n",n,f);
	return f;
}

int main()
{
	int num,result;
	printf("Enter a number to calculate factorial: ");
	scanf("%d",&num);
	result=factorial(num);
	printf("Factorial of %d! = %d\n",num,result);

	return 0;
}