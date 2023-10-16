


import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class T54 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		List<Integer> keyList = new ArrayList<>();// 记录顺序
		Arrays.stream(input.split(",")).forEach(s -> {
			Integer key = Integer.parseInt(s);
			map.put(key, map.containsKey(key) ? map.get(key) + 1 : 1);
			if (!keyList.contains(key)) {
				keyList.add(key);
			}
		});
		// System.out.println(map);
		// System.out.println(keyList);
		List<Map<Integer, Integer>> mapList = new ArrayList<>();
		for (Integer key : keyList) {
			Map<Integer, Integer> m = new HashMap<>();
			m.put(key, map.get(key));
			mapList.add(m);
		}
		mapList.sort(new Comparator<Map<Integer, Integer>>() {
			@Override
			public int compare(Map<Integer, Integer> m1, Map<Integer, Integer> m2) {
				Integer v1 = m1.values().iterator().next();
				Integer v2 = m2.values().iterator().next();
				if (v1 > v2)
					return -1;
				if (v2 < v1)
					return 1;
				if (v2 == v1) {
					// 取key顺序来判断
					Integer k1 = m1.keySet().iterator().next();
					Integer k2 = m2.keySet().iterator().next();
					if (k1 > k2)
						return 1;
					if (k1 < k2)
						return -1;
				}
				return 0;
			}
		});
		mapList.forEach(m -> {
			System.out.print(m.keySet().iterator().next() + ",");
		});
	}
}

