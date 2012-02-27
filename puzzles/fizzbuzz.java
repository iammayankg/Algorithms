/*Slightly more efficient and neat version of fizzbuzz type program
 * 
 * Given a range of integers print "Hello" if divisible by den1
 * "World" if divisible by den2
 * "Fizzbuzz" if divisible by both
 */
 
import java.io.*;
class fizzbuzz
{
	public static void main(String args[]) throws IOException
	{
		int count=0;
		int num=20;
		int den1=3;
		int den2=5;
		for(int i=1;i<=num;i++)
		{
			count = (((i%den1)==0)?1:0) + (((i%den2)==0)?2:0);
			switch(count)
			{
				case 1:
					System.out.println("Hello");
					break;
				case 2:
					System.out.println("World");
					break;
				case 3:
					System.out.println("Fizzbuzz");
					break;
				}
			}
	}
}
