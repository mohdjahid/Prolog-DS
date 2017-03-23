import java.util.ArrayList;
import java.util.Collections;

class LargestArrayConsecutive
{
	static int set[][]=new int[9][9];
	public static void main(String... args)
	{
		int a[]={2,0,2,1,4,3,1,0};
		int j;
		ArrayList<Integer> diff=new ArrayList<Integer>();
				
		for(int i=0;i<a.length-1;i++)
		{
			for(j=i;j<a.length;j++)
			{
				if(set[i][a[j]] == 1)
					break;
				else
					set[i][a[j]]=1;
			}
			diff.add(j-i);
		}
		
		System.out.println(Collections.max(diff));

	}
}