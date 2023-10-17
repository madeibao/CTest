import java.util.Scanner;


输入	2,5,2
输出	5,-1,5
说明	
第一个2的下一个更大的数是5;

数字5找不到下一个更大的数;

第二个2的下一个最大的数需要循环搜索，结果也是 5


public class T66 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String input = sc.nextLine();
		String strArr[] = input.split(",");
		int nums[] = new int[strArr.length];
		for (int i = 0; i < strArr.length; i++) {
			nums[i] = Integer.parseInt(strArr[i]);
		}
		for (int objIndex = 0; objIndex < nums.length; objIndex++) {
			int next = -1;
			for (int nextObj = objIndex + 1; nextObj != objIndex;) {
				if (nextObj == nums.length) {
					nextObj = 0;
				}
				// System.out.println(nextObj+"->>"+nums[nextObj]);
				if (nums[nextObj] > nums[objIndex]) {
					next = nums[nextObj];
					// System.out.println(nums[objIndex]+"-"+nums[nextObj]);
					break;
				}
				nextObj = (++nextObj) % nums.length; // for循环的第三个要素
			}
			System.out.print(next+" ");
		}
	}
}

