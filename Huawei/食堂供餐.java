

import java.util.Scanner;

/**
 * @Author
 * @Date 2023/6/11 10:19
 */
public class 食堂供餐 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[] p = new int[n];
            int totalPeople = 0;
            for (int i = 0; i < n; i++) {
                p[i] = in.nextInt();
                totalPeople = p[i];
            }

            int left = 0;
            int right = totalPeople - m;
            while (left < right) {
                int mid = (left + right) / 2;
                if (check(mid, m, n, p)) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }

            System.out.println(left);

        }
    }

    // 检查给定的供餐速度是否能满足要求
    public static boolean check(int speed, int total, int n, int[] p) {
        boolean result = true;
        for (int i = 0; i < n; i++) {
            total -= p[i];
            if (total < 0) {
                result = false;
                break;
            }
            total += speed;
        }
        return result;
    }
}
