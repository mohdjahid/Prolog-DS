#include <stdio.h>

int F[51];

int power(int x,int n)
{
	if(n==0)
		return 1;
	else if(n%2==0)
		{
			int y=power(x,n/2);
			return y*y;
		}
		else
			return x*power(x,n-1);
}

int main()
{
	int x,result,n;
	
	printf("Enter value of X and n to calculate Power : ");
	scanf("%d%d",&x,&n);
	result=power(x,n);
	printf("Power( %d, %d ) : %d\n",x,n,result);

	return 0;
}