import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
 
/**
 * 支持优先级的队列
 * 
 * @since 2023.10.26
 * @version 0.1
 * @author Frank
 *
 */
public class PriorityQueue {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	while (sc.hasNext()) {
	    String input = sc.nextLine();
	    int[][] elements = getElements( input );
	    sort( elements );
	    output( elements );
	}
    }
 
    private static int[][] getElements( String input )
    {
	List<int[]> eleList = new ArrayList();
	
	int indexLeft = 0;
	int indexRight = 0;
	
	while( indexLeft != -1)
	{
	    indexLeft = input.indexOf( "(",  indexRight );
	    indexRight = input.indexOf( ")",  indexRight );
	    if( indexLeft == -1 )
	    {
		break;
	    }
	    String eleStr = input.substring( indexLeft + 1, indexRight );
	    String[] eleArr = eleStr.split( "," );
	    int[] element = new int[2];
	    element[0] = Integer.parseInt( eleArr[0] );
	    element[1] = Integer.parseInt( eleArr[1] );
	    eleList.add( element );
	    
	    indexRight += 1;
	}
	
	int[][] ret = new int[eleList.size()][2];
	for( int i = 0; i < eleList.size(); i ++ )
	{
	    ret[i] = eleList.get( i );
	}
	
	return ret;
    }
    
    private static void sort( int[][] elements) {
	Arrays.sort( elements, new Comparator<int[]>() {
	    @Override
	    public int compare(int[] o1, int[] o2) {
		return o2[1] - o1[1];
	    }
	    
	} );
    }
 
    private static void output( int[][] elements ) {
	StringBuffer sb = new StringBuffer();
	for( int i = 0; i < elements.length; i ++ )
	{
	    if( i > 0 && ( elements[i][0] ==  elements[i - 1][0] ) && ( elements[i][1] ==  elements[i - 1][1] )  ) {
		continue;
	    }
	    sb.append( elements[i][0] + "," );
	}
	String ret = sb.toString();
	ret = ret.substring( 0, ret.length() - 1);
	System.out.println( ret );
    }
}