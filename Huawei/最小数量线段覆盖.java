

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;
 
/**
 * 最少线段覆盖
 * 
 * @since 2023.09.23
 * @version 0.1
 * @author Frank
 *
 */
public class MinLineCount {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			int count = Integer.parseInt(input);
 
			List<int[]> lines = new ArrayList<>();
			for (int i = 0; i < count; i++) {
				input = sc.nextLine();
				String[] strStartEnd = input.split(",");
				int[] startEnd = new int[2];
				startEnd[0] = Integer.parseInt(strStartEnd[0]);
				startEnd[1] = Integer.parseInt(strStartEnd[1]);
				lines.add(startEnd);
			}
			processMinLineCount( lines);
		}
	}
 
	private static void processMinLineCount( List<int[]> lines) {
		// 1. 排序
		Comparator<int[]> cmp = new Comparator<int[]>() {
			@Override
			public int compare(int[] o1, int[] o2) {
				for (int i = 0; i < o1.length; i++) {
					if (o1[i] != o2[i]) {
						return o1[i] - o2[i];
					}
				}
				return 0;
			}
		};
 
		lines.sort(cmp);
 
		// 2. 分段
		class LinePart {
			int start; // 起始点，包含在内
			int end; // 终止点，包含在内
			int startIdx; // 对应lines中的起始下标，包含在内
			int endIdx; // 对应lines中的终止下标，包含在内
		}
 
		List<LinePart> lpList = new ArrayList<LinePart>();
		LinePart tmpLP = new LinePart();
		for (int i = 0; i < lines.size(); i++) {
			int[] tmpLine = lines.get(i);
			if (i == 0) {
				tmpLP.start = tmpLine[0];
				tmpLP.end = tmpLine[1];
				tmpLP.startIdx = 0;
				tmpLP.endIdx = 0;
				lpList.add( tmpLP );
				continue;
			}
			
			// 不是同一个区间
			if( tmpLine[0] > tmpLP.end )
			{
				tmpLP = new LinePart();
				tmpLP.start = tmpLine[0];
				tmpLP.end = tmpLine[1];
				tmpLP.startIdx = i;
				tmpLP.endIdx = i;
				lpList.add( tmpLP );
				continue;
			}else  // 同一个区间
			{
				tmpLP.end = tmpLine[1];
				tmpLP.endIdx = i;
			}
			
		}
		
		//3.逐段求和
		int count = 0;
		for( int i = 0; i < lpList.size(); i ++ )
		{
			LinePart lpPart = lpList.get( i );
			List<int[]> tmpList = new ArrayList<int[]>();
			for( int j = lpPart.startIdx; j <= lpPart.endIdx; j ++ )	//  j <= lpPart.endIdx，包含在内
			{
				int[] tmpLine = lines.get( j );
				int[] copy = new int[2];
				copy[0] = tmpLine[0];
				copy[1] = tmpLine[1];
				tmpList.add( copy );
			}
			int partCount = getPartMinCount( tmpLP.start, tmpLP.end, tmpList );
			count += partCount;
		}
		System.out.println( count );
 
	}
	
	private static int getPartMinCount( int start, int end, List<int[]> list)
	{
		if( start >= end )
		{
			return 0;
		}
		int minCount = list.size();
		for( int i = 0; i < list.size(); i ++ )
		{
			int tmpCount = 0;
			int[] cur = list.get( i );
			
			// 当它已经无法覆盖
			if( cur[0] > start )
			{
				break;
			}
			
			// 如果end小于start，那这样的线段根本不需要
			if( cur[1] < start  )
			{
				continue;
			}
			
			list.remove( i );
			
			tmpCount ++;
			tmpCount += getPartMinCount( cur[1], end, list);
			
			list.add( i, cur );
			if( tmpCount < minCount )
			{
				minCount = tmpCount;
			}
		}
		
		return minCount;
	}
}