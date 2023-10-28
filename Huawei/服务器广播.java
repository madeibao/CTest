import java.util.Scanner;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
 
/**
 * 服务器广播
 * 
 * @since 2023.10.15
 * @version 0.1
 * @author Frank
 *
 */
public class ServerBroadcastCount {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			String[] strNumbers = input.split(" ");
			int count = strNumbers.length;
			int[][] numbers = new int[count][count];
			for (int i = 0; i < count; i++) {
				if (i != 0) {
					// 首行已读取
					input = sc.nextLine();
					strNumbers = input.split(" ");
				}
				int[] lineNum = new int[count];
				for (int j = 0; j < count; j++) {
					lineNum[j] = Integer.parseInt(strNumbers[j]);
				}
				numbers[i] = lineNum;
			}
			processServerBroadcastCount(numbers);
		}
	}
 
	private static void processServerBroadcastCount( int numbers[][] )
	{
		Set<Integer> usedNumber = new HashSet<Integer>();
		List<Set<Integer>> connectionList = new ArrayList<Set<Integer>>();
		
		for( int i = 0; i < numbers.length; i ++ )
		{
			if( usedNumber.contains( i ) )
			{
				continue;
			}
			Set<Integer> newConnectionSet = new HashSet<Integer>();
			usedNumber.add( i );
			newConnectionSet.add( i );
			initConnectionSet( i, usedNumber, newConnectionSet, numbers);
			connectionList.add(newConnectionSet );
		}
		System.out.println( connectionList.size() );
	}
 
	private static void initConnectionSet(int idx, Set<Integer> usedNumber, Set<Integer> newConnectionSet,
			int numbers[][]) {
		for( int i = 0; i < numbers.length; i ++ )
		{
			if( i == idx )
			{
				continue;
			}
			int idxCheck = numbers[idx][i];
			if( usedNumber.contains( i ) || idxCheck == 0 )
			{
				continue;
			}
			
			usedNumber.add( i );
			newConnectionSet.add( i );
			initConnectionSet( i, usedNumber, newConnectionSet, numbers);
		}
	}
 
}