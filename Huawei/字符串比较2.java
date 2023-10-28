

import java.util.Scanner;
 
/**
 * 字符串比较
 * @since 2023.10.09
 * @version 0.1
 * @author Frank
 *
 */
public class StringComparation {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String strA = sc.nextLine();
			String strB = sc.nextLine();
			String strV = sc.nextLine();
			int v = Integer.parseInt( strV );
			processStringComparation( strA, strB, v );
		}
	}
	
	private static void processStringComparation( String strA, String strB, int v )
	{
		int[] diffAbs = new int[ strA.length() ];
		for( int i = 0; i < diffAbs.length; i ++ )
		{
			int eachDiffAbs = Math.abs( strA.charAt( i ) - strB.charAt( i ) );
			diffAbs[i] = eachDiffAbs;
		}
		
		int leftIndex = 0;
		int rightIndex = 0;
		int maxCount = 0;
		int curSum = diffAbs[0];
		while( rightIndex <= diffAbs.length - 1 )
		{
			if( curSum > v )
			{
				if( leftIndex >= diffAbs.length - 1 )
				{
					break;
				}
				curSum -= diffAbs[ leftIndex ];
				leftIndex ++;				
				if( rightIndex < leftIndex )
				{					
					rightIndex = leftIndex;
					curSum += diffAbs[ rightIndex ];
				}
				continue;
			}
			
			// curSum <= v
			if( rightIndex - leftIndex + 1 >= maxCount )
			{
				maxCount = rightIndex - leftIndex + 1;
			}
			
			if( rightIndex >= diffAbs.length - 1 )
			{
				break;
			}
			rightIndex ++;
			curSum += diffAbs[ rightIndex ];
		}
		
		System.out.println( maxCount );
	}
}