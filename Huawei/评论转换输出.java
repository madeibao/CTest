

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
 
/**
 * 评论转换输出
 * 
 * @since 2023.10.18
 * @version 0.1
 * @author Frank
 *
 */
public class CommentsTransfer {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			String[] inputStr = input.split(",");
			int count = inputStr.length / 2;
			String[] contents = new String[count];
			int[] childrenCnt = new int[count];
			for (int i = 0; i < count; i++) {
				contents[i] = inputStr[2 * i];
				childrenCnt[i] = Integer.parseInt(inputStr[2 * i + 1]);
			}
			processCommentsTransfer(contents, childrenCnt);
		}
	}
 
	private static void processCommentsTransfer(String[] contents, int[] childrenCnt) {
		List<List<String>> commentsList = new ArrayList<List<String>>();
		int curLevel = 0;
		int curIndex = 0;
		while (curIndex <= contents.length - 1) {
			curIndex = processEachLevel(curIndex, curLevel, commentsList, contents, childrenCnt);
		}
		System.out.println( commentsList.size() );
		for( int i = 0; i < commentsList.size(); i ++ )
		{
			List<String> comments = commentsList.get( i );
			for( int j = 0; j < comments.size(); j ++ )
			{
				System.out.print( comments.get( j ));
				if( j < comments.size() - 1 )
				{
					System.out.print( "," );
				}else
				{
					System.out.println();
				}
			}
		}
	}
 
	private static int processEachLevel(int curIndex, int curLevel, List<List<String>> commentsList, String[] contents,
			int[] childrenValues) {
		int index = curIndex;
		
		List<String> comments;
		if( curLevel >= commentsList.size() )
		{
			comments = new ArrayList<String>();
			commentsList.add( comments );
		}else
		{
			comments = commentsList.get( curLevel );
		}
		
		int curChildrenCnt = childrenValues[ curIndex ];
		
		comments.add( contents[index] );
		index ++;
		
		if( curChildrenCnt == 0 )
		{
			return index;
		}
		// 有children的情况
		for( int i = 0; i < curChildrenCnt; i ++ )
		{			
			index = processEachLevel( index, curLevel + 1, commentsList, contents, childrenValues);
		}
		return index;
	}
}