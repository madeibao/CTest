

import java.util.Arrays;
import java.util.Scanner;

/**
 * 一次变换要想得到最小 那么交换时，肯定是将最小的字符往前提 如果那个最小字符有多个，则肯定是提取最后一个
 * 比如 bacada===> aacadb=> 最后一个a和首字符交换 
 *  解决思路 先排序 查找从前往后字符串变化的地方
 */
public class T41 {
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		String rawWord=sc.nextLine();
		char[] cArr=rawWord.toCharArray();
		Arrays.sort(cArr);
		boolean flag=false;
		for(int i=0;i<cArr.length;i++) {
			if(cArr[i]!=rawWord.charAt(i)) {
				char obj=cArr[i];//要替换的目标字符
				int lastIndex=rawWord.lastIndexOf(obj); //要替换的目标字符 最后的索引
				StringBuilder sb=new StringBuilder(rawWord);
				char rawObj=sb.charAt(i);//目标字符提前的索引对应字符 目标字符要和谁换
				sb.setCharAt(i, obj);
				sb.setCharAt(lastIndex, rawObj);
				System.out.println(sb.toString());
				flag=true;
				break; 
			}
		}
		if(flag==false){
			System.out.println(rawWord);
		}
	}
}

