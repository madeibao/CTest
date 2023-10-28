import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;
import java.util.Scanner;
 
/**
 * 不开心的小朋友
 * @since 2023.09.12
 * @version 0.1
 * @author Frank
 *
 */
public class UnhappyKids {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			int count = Integer.parseInt( input );
			input = sc.nextLine();
			String[] numbers = input.split( " " );
			processUnhappyKids( count, numbers );
		}
		
	}
	
	private static void processUnhappyKids( int count, String numbers[] )
	{
		Set<Integer> shakeToy = new HashSet<Integer>();
		List<Integer> kidQueue = new ArrayList<Integer>();
		Set<Integer> allKidSet = new HashSet<Integer>();
		int unhappyCnt = 0;
		
		for( int i = 0; i < numbers.length; i ++ )
		{
			int currentNum = Integer.parseInt( numbers[i] );
			
			// 如果首次出现
			if( !allKidSet.contains( currentNum ))
			{
				// 摇摇车满了
				if( shakeToy.size() >= count )
				{
					kidQueue.add( currentNum );					
				}else
				{
					shakeToy.add( currentNum );
				}		
				allKidSet.add( currentNum );
			}else  // 第二次出现，则在排队或者在玩游戏中
			{
				
				if( shakeToy.contains( currentNum ) )
				{
					shakeToy.remove( currentNum );
					if( kidQueue.size() > 0 )
					{
						int queueFirst = kidQueue.get( 0 );
						shakeToy.add( queueFirst );
						kidQueue.remove( 0 );
					}					
				}else  // 在排队中离开，不高兴
				{	
					// 删除 Object，而不是 index，此处要转换成 Integer。
					kidQueue.remove( (Integer) currentNum );
					unhappyCnt ++;
				}
				allKidSet.remove( currentNum );
			}
		}
		System.out.println( unhappyCnt );
	}
 
}