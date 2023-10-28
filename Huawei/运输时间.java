import java.util.Scanner;
 
/**
 * 运输时间
 * @since 2023.09.21
 * @version 0.1
 * @author Frank
 *
 */
public class TransportTime {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String line = sc.nextLine();
			String[] cntDistance = line.split( " " );
			int count = Integer.parseInt( cntDistance[0] );
			int distance = Integer.parseInt( cntDistance[1] );
			
			String[] inputs = new String[count];
			for( int i = 0; i < count; i ++ )
			{
				inputs[i] = sc.nextLine();
			}			
			processTransportTime( count, distance, inputs );
		}
	}
	
	private static void processTransportTime( int count, int distance, String inputs[] )
	{
		float minTime = 0;
		for( int i = 0; i < count; i ++ )
		{
			int speed = Integer.parseInt( inputs[i] );
			float curTime = (float) distance / speed;
			if( i == 0 )
			{
				minTime = curTime;
				continue;
			}
			if( curTime < minTime - 1 )
			{
				minTime = minTime - 1;
			}else
			{
				minTime = curTime;
			}
		}
		System.out.println( minTime );
	}
 
}