
// 4
// 5F3Z-2e-9-w

// 输出	5F3Z-2E9W
// 说明	
// 字符串 S 被分成了两个部分，每部分 4 个字符；

// 注意，两个额外的破折号需要删掉。

import java.util.Scanner;

public class T44 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int num = Integer.parseInt(scanner.nextLine());
		String input = scanner.nextLine();
		String[] wordArr = input.split("-");
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i < wordArr.length; i++) {
			sb.append(wordArr[i].toUpperCase());
		}
		System.out.print(wordArr[0]);
		for (int i = 0; i < sb.length(); i++) {
			if (i % num == 0)
				System.out.print("-");
			System.out.print(sb.charAt(i));
		}
	}
}

