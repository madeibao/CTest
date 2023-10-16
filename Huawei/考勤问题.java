
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

//考勤问题
public class T38 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = Integer.parseInt(sc.nextLine());// 记录条数
		for (int i = 0; i < num; i++) {
			String input = sc.nextLine();
			String kqArr[] = input.split(" ");
			// 一、缺勤不超过1次
			int queqinCoun = 0; // 不超过1次
			for (String kq : kqArr) {
				if (kq.equals("absent")) {
					queqinCoun++;
					if (queqinCoun > 1) {
						break;
					}
				}
			}
			if (queqinCoun > 1) {
				System.out.println("false");
				break;
			}
			// 二、没有连续的迟到/早退 迟到和早退 也是连续的 相当于一天干了俩个事情 也算
			List<String> cList = new ArrayList<String>();
			cList.add("late");
			cList.add("leaveearly");
			boolean isLateOrLeaveEarly = false;
			for (int j = 1; j < kqArr.length; j++) {
				if (cList.contains(kqArr[j]) && cList.contains(kqArr[j - 1])) {
					// 出现连续的迟到/早退
					isLateOrLeaveEarly = true;
					break;
				}
			}
			if (isLateOrLeaveEarly) {
				System.out.println("false");
				break;
			}
			// 三、任意连续的7次考勤 ，缺勤/迟到/早退不超过3次 即 缺勤次数+迟到次数+早退次数<=3
			// 双指针做法
			int start = 0;
			int end = kqArr.length >= 7 ? 6 : kqArr.length;
			int count = 0;// 违规次数
			cList.add("absent");
			// 判断连个指针之间的初始值内是否已经满足false情况
			for (int k = start; k < end; k++) {
				if (cList.contains(kqArr[k])) {
					count++;
				}
			}
			if (count > 3) {
				System.out.println("false");
				break;
			}
			while (end < kqArr.length - 1) {
				// 指针右侧
				end++;
				if (cList.contains(kqArr[end])) {
					count++;// 加进来的是满足的
				}
				if (cList.contains(kqArr[start])) {
					count--;// 移出去的也是满足的
				}
				start++; // 左指针也需要右移1位 保持两个指针之间能取得连续7位
				if (count > 3) {
					break;
				}
			}
			if (count > 3) {
				System.out.println("false");
				break;
			}
			System.out.println("true");
		}
	}
}

