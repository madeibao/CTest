

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

/**
 * @Author 
 * @Date 2023/5/4 23:30
 */
public class 硬件产品销售方案 {

    public static List<Integer> path = new ArrayList<>();
    public static List<List<Integer>> result = new ArrayList<>();
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int amount = Integer.parseInt(in.nextLine());
            int[] prices = Arrays.stream(in.nextLine().split(", "))
                    .mapToInt(Integer::parseInt).toArray();
            path.clear();
            result.clear();
            dfs(prices, amount, 0, 0);
            System.out.println(result);
        }
    }

    public static void  dfs(int[] prices, int amount, int startIndex, int sum) {
        // 大于采购金额则不满足
        if (sum > amount) {
            return;
        }
        // 刚好等于采购金额
        if (sum == amount) {
            result.add(new ArrayList<>(path));
            return;
        }
        // 可重复选择
        for (int i = startIndex; i < prices.length; i++) {
            path.add(prices[i]);  // 选择
            dfs(prices, amount, i, sum + prices[i]);
            path.remove(path.size() - 1);  // 回溯 不选择
        }
    }

}
