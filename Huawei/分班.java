import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
 
/**
 * 篮球比赛
 * 
 * @since 2023.09.15
 * @version 0.1
 * @author Frank
 *
 */
public class ClassCheck {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while (sc.hasNext()) {
			String input = sc.nextLine();
			processClassCheck(input);
		}
	}
 
	private static void processClassCheck(String input) {
		String[] kidsInfoStr = input.split(" ");
		if (kidsInfoStr == null || kidsInfoStr.length == 0) {
			System.out.println("ERROR");
			return;
		}
 
		List<Integer>[] classInfo = new ArrayList[2];
		classInfo[0] = new ArrayList<Integer>();
		classInfo[1] = new ArrayList<Integer>();
 
		int curClass = 1;
		for (int i = 0; i < kidsInfoStr.length; i++) {
			String eachRecord = kidsInfoStr[i];
			String[] recordDetail = eachRecord.split("/");
			if (recordDetail == null || recordDetail.length != 2) {
				System.out.println("ERROR");
				return;
			}
			int num;
			try {
				num = Integer.parseInt(recordDetail[0]);
			} catch (NumberFormatException e) {
				System.out.println("ERROR");
				return;
			}
			if ("Y".equals(recordDetail[1])) {
				classInfo[curClass].add(num);
			} else if ("N".equals(recordDetail[1])) {
				curClass ^= 1;
				classInfo[curClass].add(num);
			} else {
				System.out.println("ERROR");
				return;
			}
		}
 
		Collections.sort(classInfo[0]);
		Collections.sort(classInfo[1]);
		if (classInfo[1].size() > 0 && classInfo[1].get(0) < classInfo[0].get(0)) {
			List tmp = classInfo[0];
			classInfo[0] = classInfo[1];
			classInfo[1] = tmp;
		}
 
		for (int i = 0; i < classInfo.length; i++) {
			if (classInfo[i].size() == 0) {
				// 如果为 0，一定是第二个
				System.out.println();
				break;
			}
			for (int j = 0; j < classInfo[i].size(); j++) {
				System.out.print(classInfo[i].get(j));
				if (j != classInfo[i].size() - 1) {
					System.out.print(" ");
				} else {
					System.out.println();
				}
			}
		}
 
	}
 
}