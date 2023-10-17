


import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

public class T30 {
	static int sum=0;
	public static void main(String[] args) {
		String input="4 3 2 3 5 2 1";
		String[] strArr=input.split(" ");
		List<Integer> numList=new LinkedList<Integer>();
		for(int i=0;i<strArr.length;i++){
			numList.add(Integer.parseInt(strArr[i]));
			sum+=Integer.parseInt(strArr[i]);
		}
		numList.sort(new Comparator<Integer>() {
			@Override
			public int compare(Integer o1, Integer o2) {
				if(o1>o2)return -1;
				if(o1<o2)return 1;
				return 0;
			}
		});
		//求可能的分成的桶数 最小为1桶 最多为n桶 而桶数必须是和的因数
		List<Integer> groupList=new ArrayList<Integer>();
		for(int i=2;i<=numList.size();i++){
			if(sum%i==0) groupList.add(i);
		}
		int res=sum;//默认为1组 
		for(Integer groupNum:groupList){
			if(canGroup(groupNum,numList)){
				res=sum/groupNum; //groupNum分了几组  由于已经排过序 所以越往后分组越细 直接计算结果即可。
			}
		}
		System.out.println(res);
	}
	public static boolean canGroup(int groupNum,List<Integer> numList){
		int avg=sum/groupNum;
		Map<Integer, Integer> map=new HashMap<Integer, Integer>();// 1，桶名 2桶值
		//初始化分组 组名和默认值
		for(int i=0;i<groupNum;i++){
			map.put(i, 0);
		}
		for(Integer num:numList){
			for(int i=0;i<groupNum;i++){
				if(map.get(i)+num<=avg){
					map.put(i, map.get(i)+num);
					break;
				}
			}
//			System.out.println(map); 需要查看分组过程 可以打开注释
		}
		for(int i=0;i<groupNum;i++){
			if(map.get(i)!=avg){
				return false;
			}
		}
		return true;
	}
}
