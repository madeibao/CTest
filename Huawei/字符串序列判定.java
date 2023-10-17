


import java.util.ArrayList;
import java.util.List;

public class T21 {
	public static void main(String[] args) {
		String input1 = "ace";
		String input3 = "abaeceece";
		String input2 = "abcde";
		// 解决思路：将input1的所有字符在2中出现的索引全部记录下来，将索引存起来 最后按顺序去判断
		List<List<Integer>> indexList = new ArrayList<List<Integer>>();
		for (int i = 0; i < input1.length(); i++) {
			char c = input1.charAt(i);
			List<Integer> indexItem = new ArrayList<>();
			StringBuilder stringBuilder = new StringBuilder(input2);
			while (stringBuilder.indexOf(c + "") != -1) {
				indexItem.add(stringBuilder.indexOf(c + ""));
				stringBuilder.setCharAt(stringBuilder.indexOf(c + ""), '_');
			}
			if (indexItem.size() != 0)
				indexList.add(indexItem);
		}
		// System.out.println(indexList); [[0], [3], [2, 4, 5, 6]]
		// 找出可能出现的排序 即逐个列表查找，若能找到合适的序列，则成功
		List<List<Integer>> resList = new ArrayList<>();
		for (int i = 0; i < indexList.size(); i++) {
			resList = mult2(resList, indexList.get(i));
			// System.out.println(resList);
		}
		System.out.println(resList);
		int finalMaxIndex = -1;// 最后的且最大的那个有序的
		for (List<Integer> indexList1 : resList) {
			boolean flag = true;// 是否出现是有序的
			Integer last = indexList1.get(0);// 上一个索引
			for (int i = 1; i < indexList1.size(); i++) {
				if (indexList1.get(i) <= last) {
					flag = false;
					break;
				}
			}
			if (flag) {
				// 出现一次有序的了
				if (indexList1.get(indexList1.size() - 1) > finalMaxIndex) {
					finalMaxIndex = indexList1.get(indexList1.size() - 1);
				}
			}
		}
		System.out.println(finalMaxIndex);
	}

	// 二维数组 乘以一维数组
	public static List<List<Integer>> mult2(List<List<Integer>> list1,
			List<Integer> list2) {
		List<List<Integer>> objList = new ArrayList<>();
		if (list1.size() == 0) {
			for (Integer item2 : list2) {
				List<Integer> item11 = new ArrayList<>();
				item11.add(item2);
				objList.add(item11);
			}
			return objList;
		}
		for (List<Integer> item : list1) {
			for (Integer item2 : list2) {
				List<Integer> item11 = new ArrayList<>();
				item11.addAll(item);
				item11.add(item2);
				objList.add(item11);
			}
		}
		return objList;
	}
}

