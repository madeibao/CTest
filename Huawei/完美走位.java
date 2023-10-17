

import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class T26 {
	public static void main(String[] args) {
		String input = "WASDAASDSDAS";
		char[] chArr = input.toCharArray();
		char C[] = { 'W', 'A', 'S', 'D' };
		Map<Character, Integer> chCountMap = new HashMap<Character, Integer>();
		for (char c : C) {
			chCountMap.put(c, 0);
		}
		// 统计每个字符出现的次数
		for (char c : chArr) {
			chCountMap.put(c, chCountMap.get(c) + 1);
		}
		int avgLen = input.length() / 4;
		// 计算每个字符的差值
		for (char c : C) {
			chCountMap.put(c, chCountMap.get(c) - avgLen);
		}
		// 计算每个字符正和负的情况 其实就是统计正出现的个数即可
		for (char c : C) {
			int count = chCountMap.get(c);
			if (count <= 0)
				chCountMap.remove(c); // 移除负数次数的
		}
		int min = count(input, chCountMap);
		int reverseMin = count(new StringBuilder(input).reverse().toString(), chCountMap);
		if (min < reverseMin) {
			System.out.println(min);
		} else {
			System.out.println(reverseMin);
		}
	}

	// 统计双指针找满足条件的最小子串长度
	public static int count(String input, Map<Character, Integer> chCountMap) {
		int start = 0; // 开始索引
		int end = 1;// 结束索引
		int min = Integer.MAX_VALUE;
		String word;
		while (end < input.length()) {
			word = input.substring(start, end);
			if (!chCountMap.containsKey(word.charAt(0))) {
				// 首字母不是 干掉
				start++;
				end++;
				continue;
			}
			if (check(word, chCountMap)) {
				start = end;
				if (word.length() < min) {
					min = word.length();
				}
				end++;
			} else {
				end++;
			}
		}
		return min;
	}

	// 统计 字符串中是否有满足map中字符出现个数的
	public static boolean check(String word, Map<Character, Integer> wordMap) {
		char[] chArr = word.toCharArray();
		Map<Character, Integer> cMap = new HashMap<>();
		for (char c : chArr) {
			if (cMap.containsKey(c)) {
				cMap.put(c, cMap.get(c) + 1);
			} else {
				cMap.put(c, 1);
			}
		}
		Set<Character> keySet = wordMap.keySet();
		boolean flag = true;
		for (Character key : keySet) {
			if (!cMap.containsKey(key))
				return false;
			if (wordMap.get(key) > cMap.get(key))
				return false;
		}
		if (flag)
			return true;
		return false;
	}
}

