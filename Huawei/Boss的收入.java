

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public abstract class T61 {
	static Map<Integer, List<Map<Integer, Integer>>> mapList = new HashMap<Integer, List<Map<Integer, Integer>>>();
	// {"上级分销":[{"下级分销id":"收入"}，{"下级分销id":"收入"}]}
	static List<Integer> parentIdList = new ArrayList<>();// 记录所有的父经销商 后面方便使用
	// {"boss":{income:100,child:[{"income":100,child:[]}]}}
	static int bossId;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = Integer.parseInt(sc.nextLine());
		for (int i = 0; i < num; i++) {
			// id 上级id 收入
			String[] str = sc.nextLine().split(" ");
			int nowId = Integer.parseInt(str[0]);
			int parentId = Integer.parseInt(str[1]);
			int income = Integer.parseInt(str[2]);
			Map<Integer, Integer> map = new HashMap<>();
			map.put(nowId, income);
			if (mapList.containsKey(parentId)) {
				mapList.get(parentId).add(map);
			} else {
				List<Map<Integer, Integer>> maps = new ArrayList<>();
				maps.add(map);
				mapList.put(parentId, maps);
				parentIdList.add(parentId);
			}
		}
		bossId = findBossId();
		System.out.println(mapList);
//		System.out.println(findBossId());
		calc(bossId, bossId);
		System.out.println(bossId+" "+bossSum);
	}

	// 找出boss
	public static Integer findBossId() {
		Integer bossId = null;
		// 遍历map的 可以 如果key不是其他经销商的子节点 那么就为boss
		for (Integer pId : parentIdList) {
			boolean flag = false;// 该父id是否在 其他的子节点中
			for (Integer pID1 : parentIdList) {
				if (pId != pID1) {
					if (mapList.get(pID1).contains(pId)) {
						flag = true;
						break;
					}
				}
			}
			if (flag == false) {
				bossId = pId;
				break;
			}
		}
		return bossId;
	}

	// 找出某个子节点的子经销商的提成
	static Integer bossSum = 0;

	public static Integer calc(int id, int parentId) {
		// System.out.println("正在查找id->"+id);
		if (id != bossId) {
			// 获取本金
			int self = 0;
			if (mapList.containsKey(parentId)) {
				for (Map<Integer, Integer> m : mapList.get(parentId)) {
					if (m.keySet().iterator().next() == id) {
						self = m.get(id);
						// System.out.println("本金->"+m.get(id));
						break;
					}
				}
			}
			if (mapList.containsKey(id)) {
				for (Map<Integer, Integer> m2 : mapList.get(id)) {
					self += calc(m2.keySet().iterator().next(), id);
				}
			}
			// System.out.println(id+"->"+(self/100)*15);
			return (self / 100) * 15;
		} else {
			for (Map<Integer, Integer> m3 : mapList.get(bossId)) {
				int id1 = m3.keySet().iterator().next();
				// System.out.println("第一层："+id1);
				bossSum += calc(id1, bossId);
			}
		}
		return 0;
	}
}
