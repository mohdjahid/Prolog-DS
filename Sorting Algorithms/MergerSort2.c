#include <stdio.h>

void mergeArray(int array[],int nL,int nR)
{
	int i=0,j=0,k=0,left[10],right[10];
	
	for(i=0;i<nL;i++)
		left[i]=array[i];

	for(i=nL;i<nL+nR;i++)
		right[i-nL]=array[i];

	i=0;
	while(i<nL && j<nR)
	{
		if( left[i]<= right[j] )
		{
			array[k]=left[i];
			i++;
		}
		else
		{
			array[k]=right[j];
			j++;
		}
		k++;
	}
	while(i<nL)
	{
			array[k]=left[i];
			k++;		i++;
	}
	while(j<nR)
	{
		
			array[k]=right[j];
			k++;		j++;
	}
}

void mergeSort(int a[],int n)
{
	if(n<2)
		return ;
	
	int mid=n/2;
	
	mergeSort(a,mid);
	mergeSort(a,n-mid);
	
	mergeArray(a,mid,n-mid);
}

int main()
{
	int arr[10];
	int n,i;
	printf("Enter the number of Elemenst : ");
	scanf("%d",&n);
	printf("Enter %d Elements\n",n);

	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);

	mergeSort(arr,n);

	printf("Sorted Array : ");

	for(i=0;i<n;i++)
		printf(" %d ",arr[i]);
}