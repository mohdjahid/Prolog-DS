#include <stdio.h>

int F[51];

int fib(int n)
{
	if(n<=1)
		return n;
	
	if(F[n]!=-1)
		return F[n];

	int f1=fib(n-1);
	int f2=fib(n-2);
		F[n]=f1+f2;
	return F[n];
}

int main()
{
	int num,result,i;
	for(i=0;i<50;i++)
		F[i]=-1;
	printf("Enter a number to calculate fibbonacci number : ");
	scanf("%d",&num);
	result=fib(num);
	printf("Fibnacci Number of %d = %d\n",num,result);

	return 0;
}