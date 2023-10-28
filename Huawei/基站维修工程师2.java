import java.util.Scanner;
 
import java.util.List;
import java.util.ArrayList;
 
/**
 * 基站维修工程师
 * @since 2023.10.12
 * @version 0.1
 * @author Frank
 *
 */
public class MinDistance4Maintenance {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String countStr = sc.nextLine();
			int count = Integer.parseInt( countStr );
			int[][] distance = new int[count][];
			for( int i = 0; i < count; i ++ )
			{
				String line = sc.nextLine();
				String[] strNumber = line.split( " " );
				int[] number = new int[count];
				for( int j = 0; j < count; j ++ )
				{
					number[j] = Integer.parseInt( strNumber[j] );
				}
				distance[i] = number;
			}
			
			processMinDistance4Maintenance( distance );
		}
 
	}
 
	private static void processMinDistance4Maintenance( int[][] distanceMatrix )
	{
		int minDistance = Integer.MAX_VALUE;
		List<Integer> nodes = new ArrayList<Integer>();
		for( int i = 1; i < distanceMatrix.length; i ++ )
		{
			nodes.add( i );
		}		
		
		for( int i = 0; i < nodes.size(); i ++ )
		{
			int distance = 0;
			int nodeNo = nodes.get( i );
			nodes.remove( i );
			distance = distanceMatrix[0][nodeNo] + getTrackDistance( nodeNo, nodes, distanceMatrix);
			nodes.add( i, nodeNo );
			
			if( distance < minDistance )
			{
				minDistance = distance;
			}
		}
		System.out.println( minDistance );
	}
	
	/**
	 * 
	 * @param startNodeNo	起始节点
	 * @param nodes		剩余要遍历的节点
	 * @param distanceMatrix	距离矩阵
	 * @return	最小距离
	 */
	private static int getTrackDistance( int startNodeNo, List<Integer> nodes, int[][] distanceMatrix )
	{
		if( nodes.size() == 0 )
		{
			return distanceMatrix[startNodeNo][0];
		}
		
		int minDistance = Integer.MAX_VALUE;
		int distance = 0;
		for( int i = 0; i < nodes.size(); i ++ )
		{
			int curNodeNo = nodes.get( i );
			nodes.remove( i );
			distance = distanceMatrix[startNodeNo][curNodeNo] + getTrackDistance( curNodeNo, nodes, distanceMatrix);
			nodes.add( i, curNodeNo );
			
			if( distance < minDistance )
			{
				minDistance = distance;
			}
		}
		return minDistance;
	}
	
}