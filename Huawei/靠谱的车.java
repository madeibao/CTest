import java.util.Scanner;
 
/**
 * 机器人活动区域
 * @since 2023.09.26
 * @version 0.1
 * @author Frank
 *
 */
public class ReliableCar {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String line = sc.nextLine();
			processReliableCar( line );
		}
	}
 
	private static void processReliableCar( String line ) {
		StringBuffer sb = new StringBuffer();
		for( int i = 0; i < line.length(); i ++ )
		{
			char curChar = line.charAt( i );
			if( curChar > '4' )
			{
				sb.append( (char) ( curChar - 1 ) );
			}else
			{
				sb.append( curChar );
			}
		}
		String realValueStr = sb.toString();
		int realValue = 0;
		for( int i = 0; i < realValueStr.length(); i ++ )
		{
			realValue *= 9;
			realValue += ( realValueStr.charAt(i) - '0') ;
		}
		System.out.println( realValue );		
	}
		
}