



import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

//3
//2
//2,5,6,7,9,5,7
//1,7,4,3,4

public class T55 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = Integer.parseInt(sc.nextLine());
		int line = Integer.parseInt(sc.nextLine());
		List<List<Integer>> numList = new ArrayList<List<Integer>>();
		for (int i = 0; i < line; i++) {
			List<Integer> list = new ArrayList<Integer>();
			Arrays.stream(sc.nextLine().split(",")).forEach(n -> {
				list.add(Integer.parseInt(n));
			});
			numList.add(list);
		}

		List<Integer> resList = new ArrayList<Integer>();

		while (numList.size() > 0) {
			for (int i = 0; i < numList.size(); i++) {
				List<Integer> itemList = numList.get(i);
				int count = 0;
				while (count < num) {
					resList.add(itemList.get(0));
					itemList.remove(0);
					count++;
					if (itemList.size() == 0) {
						break;
					}
				}
				if (itemList.isEmpty()) {
					numList.remove(itemList);
					i--;// 注意 移除后集合的大小会少一个，因此i--，再i++之后，正好是移除后的下一个
				}
			}
		}
		System.out.println(resList);
	}
}




