
// 输入
// 3
// 3
// 4 5 6
// 1 2 3
// 4 3 2
// 1 5 2

// 输出
// 32

// ------------------------------------------------------------------------------------------


import java.util.Scanner;

/**
 * @Author 
 * @Date 2023/4/26 23:10
 */
public class MaxProfit {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int number = in.nextInt();
            int days = in.nextInt();
            int[] item = new int[number];
            int[][] prices = new int[number][days];  // 每件商品每天的价格

            for (int i = 0; i < number; i++) {
                item[i] = in.nextInt();
            }

            for (int i = 0; i < number; i++) {
                for (int j = 0; j < days; j++) {
                    prices[i][j] = in.nextInt();
                }
            }

            // 最大利润
            int res = 0;
            // 遍历每件商品，计算利润
            for (int i = 0; i < number; i++) {
                int maxPrice = 0;
                // 遍历每天的价格，计算该商品每天的利润
                for (int j = 1; j < days; j++) {
                    maxPrice += Math.max(0, prices[i][j] - prices[i][j - 1]);
                }
                // 将商品利润累计到总利润中
                res += maxPrice * item[i];
            }
            System.out.println(res);

        }
    }
}
