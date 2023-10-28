import java.util.Scanner;
 
/**
 * 字符串划分
 * @since 2023.10.10
 * @version 0.1
 * @author Frank
 *
 */
public class StringDivision {
 
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			processStringDivision( input );
		}
	}
 
	private static void processStringDivision( String input )
	{
		int asciiSum = 0;
		
		int minAscii = 'z'; // min初始化成最大值
		int maxAscii = 'a'; // max初始化成最小值
		
		for( int i = 0; i < input.length(); i ++ )
		{
			char curChar = input.charAt( i );
			asciiSum += curChar;
			if( i > 0 && i < input.length() -1 )
			{
				if( curChar < minAscii )
				{
					minAscii = curChar;
				}
				if( curChar > maxAscii )
				{
					maxAscii = curChar;
				}
			}
		}
		
		int eachMinSum = ( asciiSum - maxAscii * 2 ) / 3;
		int eachMaxSum =  ( asciiSum - minAscii * 2 ) / 3 + 1; // 向上取整，避免漏掉一些情况
		
		int leftIndex = 0;		
		int leftSum = 0;
		for( int i = 0; i < input.length() - 2; i ++ )
		{
			int curChar = input.charAt( i );
			leftSum += curChar;
			leftIndex ++;
			
			if( leftSum >= eachMinSum )
			{
				break;
			}
		}			
			
		int rightIndex = input.length() - 1;
		int rightSum = 0;
		for( int i = input.length() - 1; i > 2; i -- )
		{
			int curChar = input.charAt( i );
			rightSum += curChar;
			rightIndex --;
			if( rightSum >= eachMinSum )
			{
				break;
			}
		}
		
		while( leftSum <= eachMaxSum && rightSum <= eachMaxSum && leftIndex < rightIndex )
		{
			if( leftSum < rightSum )
			{
				int curChar = input.charAt( leftIndex );
				if( leftSum + curChar >= eachMaxSum )
				{
					break;
				}
				leftSum += curChar;
				leftIndex ++;
			}
			if( leftSum > rightSum )
			{
				int curChar = input.charAt( rightIndex );
				if( rightSum + curChar >= eachMaxSum )
				{
					break;
				}
				rightSum += curChar;
				rightIndex --;
			}
			
			if( leftIndex >= rightIndex )
			{
				break;
			}
			
			// 相等的情况
			int theOtherSum = asciiSum - leftSum - rightSum - input.charAt( leftIndex ) - input.charAt( rightIndex );
			if( theOtherSum == leftSum )
			{
				System.out.println( leftIndex + "," + rightIndex);
				return;
			}
			
			// 如果 theOtherSum 不相等，继续
			int curChar = input.charAt( leftIndex );
			if( leftSum + curChar >= eachMaxSum )
			{
				break;
			}
			leftSum += curChar;
			leftIndex ++;
			
			curChar = input.charAt( rightIndex );
			if( rightSum + curChar >= eachMaxSum )
			{
				break;
			}
			rightSum += curChar;
			rightIndex --;			
		}
		System.out.println( "0,0" );
	}
}