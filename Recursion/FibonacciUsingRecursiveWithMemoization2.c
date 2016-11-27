#include <stdio.h>

int F[51];

int fib(int n)
{
	/*
	if(F[n]==-1)
		F[n]=fib(n-1)+fib(n-2);
	
	return F[n];
	*/

	return (F[n]==-1)? F[n]=fib(n-1)+fib(n-2) : F[n];
}

int main()
{
	int num,result,i;
	for(i=0;i<50;i++)
		F[i]=-1;
	F[0]=0;
	F[1]=1;
	printf("Enter a number to calculate fibbonacci number : ");
	scanf("%d",&num);
	result=fib(num);
	printf("Fibnacci Number of %d = %d\n",num,result);

	return 0;
}