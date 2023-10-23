

import java.util.ArrayList;
import java.util.Scanner;

public class T12 {
	public static void main(String[] args) {
		System.out.println("请输入单词库（空格隔开）：");
		Scanner scanner = new Scanner(System.in);
		String input1 = scanner.nextLine();
		System.out.println("请输入单词前缀：");
		String input2 = scanner.nextLine();
		ArrayList<String> wordList = new ArrayList<>();
		StringBuilder word = new StringBuilder();
		for (int i = 0; i < input1.length(); i++) {
			char c = input1.charAt(i);
			// 字符过滤
			if (!((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))) {
				if (word.length() > 0) {
					wordList.add(word.toString());
					word.setLength(0);
				}
				continue;
			}
			;
			if (c == ' ') {
				if (word.length() > 0) {
					wordList.add(word.toString());
					word.setLength(0);
				}
				continue;
			}
			if (c == '\'') {
				if (word.length() > 0) {
					wordList.add(word.toString());
					word.setLength(0);
				}
				continue;
			}
			word.append(c);
			if (i == input1.length() - 1) {
				if (word.length() > 0) {
					wordList.add(word.toString());
					word.setLength(0);
				}
			}
		}
		boolean flag = false;// 是否找到
		for (String wd : wordList) {
			if (wd.startsWith(input2)) {
				flag = true;
				System.out.print(wd + " ");
			}
		}
		if (flag == false) {
			System.out.println(input2);
		}
	}
}

