


import java.util.Scanner;
 
/**
 * 数字加减游戏
 * 
 * @since 2023.09.08
 * @version 0.1
 * @author Frank
 *
 */
public class NumPlusMinusGame {
 
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			String[] numbers = input.split( " " );
			processNumPlusMinusGame( numbers );
		}
	}
	
	private static void processNumPlusMinusGame( String numbers[] )
	{
		int s = Integer.parseInt( numbers[0] );
		int t = Integer.parseInt( numbers[1] );
		int a = Integer.parseInt( numbers[2] );
		int b = Integer.parseInt( numbers[3] );
		
		int n = Math.abs( s - t );
		
		// 当modValue1 可能等于 modValue2，如 modValue1 等于0 或 等于 b/2 的情况。
		int modValue1 = n % b;
		int modValue2 = ( b - n % b ) % b;
		
		int i = 0;
		while( true )
		{
			int tmpModValue = ( a * i ) % b;
			if( tmpModValue == modValue1 || tmpModValue == modValue2 )
			{
				System.out.println(i);
				return;
			}
			i ++;
		}
	}
}