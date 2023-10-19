

import java.util.*;

public class MaxPrice {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String numberStr = sc.nextLine();
        String daysStr = sc.nextLine();
        int num = Integer.parseInt(numberStr);
        int days = Integer.parseInt(daysStr);

        String itemsStr = sc.nextLine();
        String[] strings = itemsStr.split(" ");
        int[] items = new int[strings.length];
        for (int i = 0; i < items.length; i++) {
            items[i] = Integer.parseInt(strings[i]);
        }
        int sum = 0;
        for (int i = 0; i < num; i++) {
            String priceArrStr = sc.nextLine();
            String[] priceArr = priceArrStr.split(" ");

            int maxProfit = 0;
            //下面使用贪心的算法，计算每件商品的最大利润
            for (int j = 1; j < priceArr.length; j++) {
                int cur = Integer.parseInt(priceArr[j]);
                int pre = Integer.parseInt(priceArr[j-1]);
                //当天价格-前一天价格，如果当天利润大于0，则卖出，否则保存
                int curProfit = cur - pre;
                maxProfit += Math.max(curProfit, 0);
            }
            sum += maxProfit * items[i];
        }
        System.out.println(sum);

    }

}
