//Modular Exponentails Pow(x,n)%M

#include <stdio.h>

int F[51];

int mod(int x,int n,int M)
{
	if(n==0)
		return 1;
	else if(n%2==0)
		{
			int y=mod(x,n/2,M)%M;
			return (y*y)%M;
		}
		else
			return ((x%M)*(mod(x,n-1,M)%M))%M;
}

int main()
{
	int x,result,n,M;
	
	printf("Enter value of X , n and M to calculate Power : ");
	scanf("%d%d%d",&x,&n,&M);
	result=mod(x,n,M);
	printf("Power( %d, %d ) : %d\n",x,n,result);

	return 0;
}