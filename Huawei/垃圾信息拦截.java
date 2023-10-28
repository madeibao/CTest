import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
 
/**
 * 垃圾信息拦截
 * @since 2023.09.20
 * @version 0.1
 * @author Frank
 *
 */
public class MsgSpam {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			int count = Integer.parseInt( input );
			
			String[] inputs = new String[count];
			for( int i = 0; i < count; i ++ )
			{
				input = sc.nextLine();
				inputs[i] = input;
			}
			
			String idA = sc.nextLine();
			processMsgSpam( idA, inputs );
		}
	}
 
	private static void processMsgSpam( String idA, String inputs[] )
	{
		Set<String> receivers = new HashSet<String>();
		Set<String> senders = new HashSet<String>();
		int aSendCnt = 0;
		int aReceiveCnt = 0;
		Map<String, Integer> msgSendCntMap = new HashMap<String, Integer>();
		
		for( int i = 0; i < inputs.length; i ++ )
		{
			String inputEle = inputs[i];
			String[] inputEleSplits = inputEle.split( " " );
			
			if( ( !inputEleSplits[0].equals( idA ) ) &&  ( !inputEleSplits[1].equals( idA ) )  )
			{
				continue;
			}
			
			if( inputEleSplits[0].equals( idA ) )
			{
				receivers.add( inputEleSplits[1] );
				aSendCnt += 1;
			}else // inputEleSplits[1].equals( idA ) 
			{
				senders.add( inputEleSplits[0] );
				aReceiveCnt += 1;
			}
			Integer tmpCnt = msgSendCntMap.get( inputEle );
			if( tmpCnt == null )
			{
				tmpCnt = 0;
			}
			tmpCnt += 1;
			msgSendCntMap.put( inputEle, tmpCnt );				
		}
		
		int recSendCnt = 0;
		for( Iterator<String> iter = senders.iterator(); iter.hasNext(); )
		{
			String tmpSender = iter.next();
			if( receivers.contains( tmpSender ) )
			{
				recSendCnt ++;
			}
		}
		int L = receivers.size() - recSendCnt;
		
		int M = aSendCnt - aReceiveCnt;
		
		boolean existsX = false;
		for( Iterator<String> iter = receivers.iterator(); iter.hasNext(); )
		{
			String tmpReceiver = iter.next();
			Integer tmpSendCnt = msgSendCntMap.get( idA + " " + tmpReceiver );
			if( tmpSendCnt == null )
			{
				// will never come here
				continue;
			}
		
			Integer tmpReceiveCnt = msgSendCntMap.get( tmpReceiver + " " + idA );
			if( tmpReceiveCnt == null )
			{
				tmpReceiveCnt = 0;
			}
			if( tmpSendCnt - tmpReceiveCnt > 5 )
			{
				existsX = true;
				break;
			}
		}
		
		boolean isSpamSender = ( L > 5 ) || ( M > 5) || existsX;
		System.out.println( isSpamSender + " " + L + " " + M );
	}
}