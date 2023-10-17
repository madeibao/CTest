
阿里巴巴找黄金（III）
题目描述
一贫如洗的椎夫阿里巴巴在去砍柴的路上，无意中发现了强盗集团的藏宝地，藏宝地有编号从0~N的箱子，每个箱子上面贴有一个数字。阿里巴巴念出一个咒语数字，查看宝箱是否存在两个不同箱子，这两个箱子上贴的数字相同，同时这两个箱子的编号之差的绝对值小于等于咒语数字，
如果存在这样的一对宝箱，请返回最先找到的那对宝箱左边箱子的编号，如果不存在则返回-1。

输入描述

第一行输入一个数字字串，数字之间使用逗号分隔，例如: 1,2.3,1
字串中数字个数》=1，<=100000; 每个数字值>=-100000，<=100000;
第二行输入咒语数字，例如: 3，咒语数字>=1，<=100000
输出描述
存在这样的一对宝箱，请返回最先找到的那对宝箱左边箱子的编号，如果不存在则返回-1


//--------------------------------------------------------------------------------------------------

import java.util.Scanner;

public class T65 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		String strArr[] = input.split(",");
		int nums[] = new int[strArr.length];
		for (int i = 0; i < strArr.length; i++) {
			nums[i] = Integer.parseInt(strArr[i]);
		}
		int objNum = sc.nextInt();
		for (int left = 0; left < nums.length; left++) {
			for (int right = 0; right < nums.length; right++) {
				if (left == right)
					continue;
				if (nums[left] != nums[right])
					continue;
				if (Math.abs(right - left) > objNum)
					continue;
				System.out.println(left);
				System.exit(0);
				break;
			}
		}
		System.out.println(-1);
	}
}

