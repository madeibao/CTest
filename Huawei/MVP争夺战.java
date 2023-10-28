import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
 
 
/**
 * MVP争夺战
 * 
 * @since 2023.09.11
 * @version 0.1
 * @author Frank
 *
 */
public class MVPCompetition {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			int count = Integer.parseInt( input );
			input = sc.nextLine();
			String[] numbers = input.split( " " );
			processMVPCompetition( numbers );
		}
	}
	
	private static void processMVPCompetition( String numbers[] )
	{
		int sum = 0;
		int maxNum = 0;
		List<Integer> numList = new ArrayList<Integer>();
		for( int i = 0; i < numbers.length; i ++ )
		{
			int tmpNum = Integer.parseInt( numbers[i] );
			if( tmpNum > maxNum )
			{
				maxNum = tmpNum;
			}
			sum += tmpNum;
			numList.add( tmpNum );
		}
		
		int maxMVPCnt = sum / maxNum;
		for( int i = maxMVPCnt; i >= 1; i --)
		{
			if( sum % i != 0 )
			{
				continue;
			}
			int aveScroe = sum / i;
			
			int[] tmpSum = new int[ i ];
			for( int j = 0; j < tmpSum.length; j ++ )
			{
				tmpSum[j] = 0;
			}
			int ret = processAverageScroe( aveScroe, tmpSum, numList );
			if( ret != -1 )
			{
				System.out.println( ret );
				return;
			}
		}
		
	}
 
	private static int processAverageScroe( int score, int[] tmpSum, List<Integer> numbers)
	{
		int ret = -1;
 
		int tmpNum = numbers.get( 0 );
		numbers.remove( 0 );
		
		for( int i = 0; i < tmpSum.length; i ++ )
		{
			if( tmpNum + tmpSum[i] > score )
			{
				continue;
			}
			
			tmpSum[i] = tmpSum[i] + tmpNum;
			boolean meet = isArrayAllScore( score, tmpSum, numbers );
			if( meet )
			{
				return score;
			}
			ret = processAverageScroe( score, tmpSum, numbers);
			if( ret != -1 )
			{
				return ret;
			}
			tmpSum[i] = tmpSum[i] - tmpNum;
		}
		
		numbers.add( 0, tmpNum );
		return ret;		
	}
	
	private static boolean isArrayAllScore( int score, int[] tmpSum, List<Integer> numbers )
	{
		boolean ret = true;
		if( numbers.size() > 0 )
		{
			return false;
		}
		for( int i = 0; i < tmpSum.length; i ++ )
		{
			if( tmpSum[i] != score )
			{
				return false;
			}
		}
		return ret;
	}
 
}