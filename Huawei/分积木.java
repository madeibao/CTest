import java.util.Scanner;
 
/**
 * 分积木
 * @since 2023.09.14
 * @version 0.1
 * @author Frank
 *
 */
public class BlockDivision {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			int count = Integer.parseInt( input );
			input = sc.nextLine();
			String[] numbers = input.split( " " );
			// 此处 count == numbers.count，可以完全不用考虑 count.
			processBlockDivision( numbers );
		}
	}
 
	private static void processBlockDivision( String numbers[] )
	{
		int xorValue = 0;
		int sum = 0;
		int minValue = Integer.MAX_VALUE;
		for( int i = 0; i < numbers.length; i ++ )
		{
			int curValue = Integer.parseInt( numbers[i] );
			xorValue ^= curValue;
			sum += curValue;
			if( curValue < minValue )
			{
				minValue = curValue;
			}
		}
		if( xorValue != 0 )
		{
			System.out.println( -1 );
		}else
		{
			System.out.println( sum - minValue );
		}
	}
	
}