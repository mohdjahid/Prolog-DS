#include <stdio.h>

void swap(int *x,int *y)
{
	int z=*x;
		*x=*y;
		*y=z;
}

int partition(int a[],int start,int end)
{
	int pivot=a[end];
	int pIndex=start;
	int i;
	for(i=start;i<end;i++)
	{
		if(a[i]<pivot)
		{
			swap(&a[i],&a[pIndex]);
			pIndex++;
		}
	}
	swap(&a[end],&a[pIndex]);
	return pIndex;
}

void quickSort(int a[],int start,int end)
{
	if(start<end)
	{
		int pIndex=partition(a,start,end);
		quickSort(a,start,pIndex-1);
		quickSort(a,pIndex+1,end);
	}
}

int main()
{
	int a[10],n,i;
	printf("Enter the number of Elements : ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the Element number a[%d] : ",i);
		scanf("%d",&a[i]);
	}
	printf("Sorted Array : ");
	quickSort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf(" a[%d] = %d ",i,a[i]);
	}
}