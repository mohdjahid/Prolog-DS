/*Given an array of integers, check if array contains a sub-array having 0 sum. 
Also, prints end-points of all such sub-arrays.
For example,

Input:  { 4, 2, -3, -1, 0, 4 }

Sub-arrays with 0 sum are

{ -3, -1, 0, 4 }
{ 0 }
 

Input:  { 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }

Sub-arrays with 0 sum are

{ 3, 4, -7 }
{ 4, -7, 3 }
{ -7, 3, 1, 3 }
{ 3, 1, -4 }
{ 3, 1, 3, 1, -4, -2, -2 }
{ 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }
*/

class SubArraySum
{
	
	static void subArray(int a[],int requiredSum)
	{
		for(int i=0;i<a.length;i++)
		{
			int sum=0;
			for(int j=i;j<a.length;j++)
			{
				sum+=a[j];

				if(sum==requiredSum){
					System.out.println("Sub Array [ "+i+" .. "+j+" ]");
				}
			}
		}
	}
	
	public static void main(String... args)
	{
		int a[]={4,2,-3,-1,0,4};
		int requiredSum=0;
		subArray(a,requiredSum);
	}
}