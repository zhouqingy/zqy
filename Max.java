package qiumax;

import java.util.Scanner;

public class Max {
	
	public static void main(String[] args)
	{
		Scanner scanner=new Scanner(System.in);
		int [] arr= new int[4];
		 for(int i=0;i<arr.length;i++){
	            arr[i]=scanner.nextInt();
	        }
		int maxsum=getmax(arr);
		System.out.println(maxsum);
		
	}
	public static int getmax(int[] arr)
	{
		if(arr.length==0)
		{
			return 0;
		}
		int sum=0;
		int maxsum=0;
		for(int i=0;i<arr.length;i++)
		{
			sum=sum+arr[i];
			if(sum<0)
			{
				sum=0;
			}
			if(sum>maxsum)
			{
				maxsum=sum;
			}
		}
		return maxsum; 
	}
}
