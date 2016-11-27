#include <stdio.h>

void mergeArray(int left[],int right[],int array[],int nL,int nR)
{
	int i=0,j=0,k=0;
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
	int left[10];
	int right[10];
	int i;
	
	for(i=0;i<mid;i++)
		left[i]=a[i];
	for(i=mid;i<n;i++)
		right[i-mid]=a[i];
	
	mergeSort(left,mid);
	mergeSort(right,n-mid);
	
	mergeArray(left,right,a,mid,n-mid);
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