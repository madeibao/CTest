


import java.util.*;
import java.util.Scanner;
public class T1 {
	static Scanner scanner=new Scanner(System.in);
	public static void main(String[] args) {
		System.out.println("请输入索引：");
		int index=Integer.parseInt(scanner.nextLine());
		System.out.println("请输入命令串：");
		String input=scanner.nextLine();
		char[] chArr=input.toCharArray();
		String cmd="";
		List<String> cmdList=new ArrayList<>();
		for(int i=0;i<chArr.length;i++){
			char item=chArr[i];
			if(item=='"'&&cmd.contains(item+"")){
				//如果是双引号 且该命令字内有 那么就是结束的双引号
				cmd+="\"";
				cmdList.add(cmd);
				cmd="";
			}else if(item=='_'&&!cmd.contains("\"")){
				//item=='_' 下划线 表示指令结束
				//!cmd.contains("\"") 该命令内前面不包含" 若包含 则是引号内的 为同一个命令字
				//cmd.equals("") 该命令字内是空的 那么就是空下划线 无意义 过滤掉
				if(!cmd.equals("")){
					cmdList.add(cmd);
					cmd="";
				}
			}
			else if(i==chArr.length-1){
				//如果是最后一位 则直接结束最后一个命令字
				cmd+=item;
				cmdList.add(cmd);
				cmd="";
			}
			else{
				//其他 情况 则是命令字
				cmd+=item;
			}
		}
		//password__a12345678_timeout_100
		//aaa_password_"a12_45678"_timeout__100_""_
		if(index>cmdList.size()-1||index<0){
			System.out.println("ERROR");
		}else{
			cmdList.set(index, "******");
			String result="";
			for(String item:cmdList){
				result+="_"+item;
			}
			result=result.replaceFirst("_", "");
			System.out.println(result);
		}
	}
}


