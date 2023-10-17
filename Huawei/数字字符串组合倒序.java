

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class T45 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		// I am an 20-years out--standing @ * -stu-dent
		String str1 = "[^0-9a-zA-Z-]";// 非法字符 //空格 @ *
		String[] items1 = input.split(str1);
		List<String> wordList = new ArrayList<String>();
		for (String w : items1) {
			if (w.replaceAll(" ", "").length() == 0) {
				continue;
			}
			if (w.indexOf("--") != -1) {
				w = w.replaceAll("--", "&");// 后面用&符号统一分割一次
			}
			if (w.indexOf("-") != -1) {
				// 解决头尾出现的问题 即可
				if (w.charAt(0) == '-' || w.endsWith("-")) {
					w = w.replaceAll("-", "&").replace(" ", "");
				}
			}
			for (String item : w.split("&")) {
				if (item.replaceAll(" ", "").length() == 0) {
					continue;
				}
				wordList.add(item);
			}
		}
		for (int i = wordList.size() - 1; i >= 0; i--) {
			System.out.print(wordList.get(i) + " ");
		}
	}
}

