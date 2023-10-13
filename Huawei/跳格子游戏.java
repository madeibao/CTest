
import java.util.Arrays;


public class Main {
    public static void main(String[] args) {
        int score[] = Arrays.asList("1 2 3 4 12 5 6 7 10 15 13 1".split(" ")).stream().mapToInt(Integer ::parseInt).toArray();
        int dpScore = DpMaxScore(score);
        System.out.println("2:" + dpScore);
    }

    /**
     * 动态规划
     * @param score
     * @return
     */
    public static int DpMaxScore(int[] score) {
        int n = score.length;
        if (n == 0) {
            return 0;
        }
        int[] dp = new int[n];
        dp[0] = score[0];
        dp[1] = Math.max(score[0], score[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(dp[i-1], dp[i-2] + score[i]);
        }
        return dp[n-1];
    }

}