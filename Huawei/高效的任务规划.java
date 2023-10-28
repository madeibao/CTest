import java.util.Scanner;
 
/**
 * 高效的任务规划
 * 
 * @since 2023.10.25
 * @version 0.1
 * @author Frank
 *
 */
public class EfficientTaskPlan {
    public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	while (sc.hasNext()) {
	    String input = sc.nextLine();
	    int groupCnt = Integer.parseInt(input);
	    int[] outputValues = new int[ groupCnt ];
	    for( int i = 0; i < groupCnt; i ++ )
	    {
		input = sc.nextLine();
		int machineCnt = Integer.parseInt( input );
		int [][] taskInfo = new int[machineCnt][2];
		for( int j = 0; j < machineCnt; j ++ )
		{
		    input = sc.nextLine();
		    String[] eachMachineStr = input.split( " " );
		    int[] eachMachine = new int[2];
		    eachMachine[0] = Integer.parseInt( eachMachineStr[0] );
		    eachMachine[1] = Integer.parseInt( eachMachineStr[1] );
		    taskInfo[j] = eachMachine;
		}
		int[] usedFlag = new int[taskInfo.length];
		for( int j = 0; j < usedFlag.length; j ++ )
		{
		    usedFlag[j] = 0;
		}
		outputValues[i] = caculateEachGroupTaskPlan( usedFlag, taskInfo, 0 );
	    }
 
	    for( int i = 0; i < groupCnt; i ++ )
	    {
		System.out.println( outputValues[i] );
	    }
	}
    }
 
    private static int caculateEachGroupTaskPlan( int[] usedFlag, int [][] taskInfo, int curTask ) {
	int minTimeTake = Integer.MAX_VALUE;
	for( int i = 0; i < taskInfo.length; i ++ )
	{
	    if( usedFlag[i] == 1 )
	    {
		continue;
	    }
	    
	    int tmpConfig = taskInfo[i][0];
	    int tmpTask = taskInfo[i][1];
	    
	    usedFlag[i] = 1;
	    int curTimeTake = tmpConfig + caculateEachGroupTaskPlan( usedFlag, taskInfo, tmpTask );
	    usedFlag[i] = 0;
	    if( curTimeTake <= curTask )
	    {
		return curTask;
	    }
	    if( curTimeTake < minTimeTake )
	    {
		minTimeTake = curTimeTake;
	    }
	    
	}	
	if( minTimeTake < curTask || minTimeTake == Integer.MAX_VALUE )
	{
	    minTimeTake = curTask;
	}
	return minTimeTake;
    }
}