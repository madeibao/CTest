import java.util.Scanner;
 

public class FindEnd {
	public static void main(String[] args) {
 
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			String[] numbersStr = input.split( " " );
			processFindEnd( numbersStr );
		}
	}
	
	private static void processFindEnd( String numbersStr[] )
	{
		int count = numbersStr.length;
		int[] numbers = new int[count];
		for( int i = 0; i < count; i ++ )
		{
			numbers[i] = Integer.parseInt( numbersStr[i] );
		}
		
		int minSteps = Integer.MAX_VALUE;
		for( int i = 1; i < count * 1.0 / 2; i ++ )
		{
			int steps = 1;
			int next = i;
			while( next < count -1 )
			{
				steps ++;
				next = next + numbers[next];
				if( next == count -1 )
				{
					if( steps < minSteps )
					{
						minSteps = steps;
					}					
					break;
				}
			}
		}
		if( minSteps == Integer.MAX_VALUE )
		{
			minSteps = -1;
		}
		System.out.println( minSteps );
	}
 
}


