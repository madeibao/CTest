import java.util.Scanner;
 
/**
 * 区块链文件转储系统
 * 
 * @since 2023.09.22
 * @version 0.1
 * @author Frank
 *
 */
public class StorageTransfer {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			int limit = Integer.parseInt(input);
			input = sc.nextLine();
			String[] strNumbers = input.split(" ");
			processStorageTransfer(limit, strNumbers);
		}
	}
 
	private static void processStorageTransfer(int limit, String strNumbers[]) {
		int[] numbers = new int[ strNumbers.length ];
		for( int i = 0; i < strNumbers.length; i ++ )
		{
			numbers[i] = Integer.parseInt( strNumbers[i] );
		}
		int left = 0;
		int right = 1;
		int tmpMax = numbers[0];
		int maxSize = 0;
		while( right <= numbers.length )
		{
			while( ( right < numbers.length ) && ( tmpMax + numbers[right] <= limit ) )
			{
				tmpMax += numbers[right]; 
				right ++;
			}
			if( tmpMax > maxSize )
			{
				maxSize = tmpMax;
			}
			if( maxSize == limit )
			{
				System.out.println( maxSize );
				return;
			}
			if( right >= numbers.length )
			{
				break;
			}
			do {
				tmpMax -= numbers[left];
				left ++;
			}while( left < numbers.length &&  tmpMax > limit);
			
		}
		
		System.out.println( maxSize );
	}
}