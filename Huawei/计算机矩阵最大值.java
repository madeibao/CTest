

import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
 
/**
 * 矩阵最大值
 * 
 * @since 2023.10.27
 * @version 0.1
 * @author Frank
 *
 */
public class MatrixMaxValue {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	while (sc.hasNext()) {
	    String input = sc.nextLine();
	    int count = Integer.parseInt( input );
	    int maxValue = 0;
	    for( int i = 0; i < count; i ++ )
	    {
		input = sc.nextLine();
		maxValue += getMaxValueEachLine( count, input );
	    }
	    System.out.println( maxValue );
	}
    }
    
    private static int getMaxValueEachLine( int count, String input )
    {
	int sourceValue = parseStringValue( input );
	int maxValue = sourceValue;
	 int curValue = sourceValue;
	// 右移 n - 1 次，求最大值
	for( int i = 0; i < count - 1; i ++ )
	{	   
	    int partValue1 = curValue / 2;
	    int partValue2 = (int) Math.round ( ( curValue % 2 ) * Math.pow( 2 , count - 1) );  // 使用round避免误差，不会越界
	    curValue = partValue1 + partValue2;
	    if( curValue > maxValue )
	    {
		maxValue = curValue;
	    }
	}
	return maxValue;
    }
 
    private static int parseStringValue( String input )
    {
	int ret = 0;
	String[] binaryArr = input.split( "," );
	for( int i = 0; i < binaryArr.length; i ++ )
	{
	    ret *= 2;
	    ret += Integer.parseInt( binaryArr[i] );
	}
	
	return ret;
    }
}