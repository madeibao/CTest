



import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int n = in.nextInt();
            System.out.println(dp(n));
        }
    }
    public static int dp(int n) {
        int nums[] = new int[n + 1];
        nums[1] = 1;
        nums[2] = 1;
        for (int i = 3 ; i <= n; i++) {
            nums[i] = nums[i - 1] + nums[i - 2];
        }
        return nums[n];
    }
}
