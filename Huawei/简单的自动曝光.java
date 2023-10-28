import java.util.Scanner;
 
/**
 * 简单的自动曝光
 * @since 2023.09.09
 * @version 0.1
 * @author Frank
 *
 */
public class ImgPixelChange {
	public static void main(String[] args) {
 
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			String[] strNumbers = input.split( " " );
			int[] numbers = convertStrNumbers2Int( strNumbers);
			processImgPixelChange( numbers );
		}
	}
	
	private static int[] convertStrNumbers2Int( String[] numbers)
	{
		int[] ret = new int[numbers.length];
		for( int i = 0; i < numbers.length; i ++ )
		{
			ret[i] = Integer.parseInt( numbers[i] );
		}
		return ret;
	}
	
	private static void processImgPixelChange( int numbers[] )
	{
		int minDiff = Integer.MAX_VALUE;
		int AVERAGE_VALUE = 128 * numbers.length;
		int finalK = -127;
		for( int k = -127; k <= 128; k ++ )
		{
			int sum = 0;
			for( int i = 0; i < numbers.length; i ++ )
			{
				int tmpNumber = numbers[i] + k;
				if( tmpNumber < 0 )
				{
					tmpNumber = 0;
				}else if( tmpNumber > 255 )
				{
					tmpNumber = 255;
				}
				sum += tmpNumber;
			}
			int diff = Math.abs( sum - AVERAGE_VALUE );
			if( diff < minDiff )
			{
				minDiff = diff;
				finalK = k;
			}
		}		
		
		System.out.println( finalK );
	}
}