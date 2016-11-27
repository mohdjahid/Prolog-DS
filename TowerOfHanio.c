#include <stdio.h>

void towerOfHanio(int height,char src,char dest,char aux)
{
	if(height>=1)
	{
		towerOfHanio(height-1,src,aux,dest);
		printf("%c -> %c\n",src,dest);
		towerOfHanio(height-1,aux,dest,src);
	}
}

int main()
{
	towerOfHanio(4,'A','C','B');
}