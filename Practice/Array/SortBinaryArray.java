/*Given an binary array, sort it in linear time and constant space. 
Output should print contain all zeroes followed by all ones.

For example,

Input: { 1, 0, 1, 0, 1, 0, 0, 1 }
Output: { 0, 0, 0, 0, 1, 1, 1, 1 }
*/

class SortBinaryArray
{
	static void sort(int a[])
	{
		int zeroes=0;
		for(int i=0;i<a.length;i++)
			if(a[i]==0)
				zeroes++;
		for(int i=0;i<a.length;i++)
		{
			a[i]=(zeroes-->0)? 0 : 1;
		}
	}
	public static void main(String...args)
	{
		int a[]={1,0,0,1,1,1,0};

		sort(a);

		for(int i=0;i<a.length;i++)
			System.out.print(a[i]+"\t");
	}
}