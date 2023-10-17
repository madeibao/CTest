
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;



public class T56 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n1 = sc.nextInt();
		int nums1[] = new int[n1];
		for (int i = 0; i < n1; i++)
			nums1[i] = sc.nextInt();

		int n2 = sc.nextInt();
		int nums2[] = new int[n2];
		for (int i = 0; i < n2; i++)
			nums2[i] = sc.nextInt();
		int count = sc.nextInt();
		List<Integer> pointSumList = new ArrayList<Integer>();
		for (int s1 : nums1) {
			for (int s2 : nums2) {
				pointSumList.add(s1 + s2);
			}
		}
		pointSumList.sort((a, b) -> a - b);
		System.out.println(pointSumList);
		int sum = 0;
		while (count > 0) {
			count--;
			sum += pointSumList.get(count);
		}
		System.out.println(sum);
	}
}

