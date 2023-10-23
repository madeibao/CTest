

// 5
// 2 2 2 2 2 5 2 2 2
// 3 3 3 3 3 1 3 3 3



// 9
//----------------------------------------------------------------------------

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String mStr = sc.nextLine();
        int m = Integer.parseInt(mStr);

        String line1 = sc.nextLine();
        String line2 = sc.nextLine();
        String[] serialNumArr = line1.split(" ");
        String[] coinArr = line2.split(" ");

        Map<Integer, int[]> map = new HashMap<>();
        for (int i = 0; i < serialNumArr.length; i++) {
            int key = Integer.parseInt(serialNumArr[i]);
            int coin = Integer.parseInt(coinArr[i]);

            int[] arr = map.getOrDefault(key, new int[]{0, 0});
            arr[0] = coin;
            arr[1]++;
            map.put(key, arr);
        }

        int sum = 0;
        for (int key : map.keySet()) {
            int[] ints = map.get(key);
            //计算不缓存情况下，需要的金币数量
            int coin = ints[0];
            int unCacheVal = coin * ints[1];
            int cacheVal = coin + m;
            int val = Math.min(unCacheVal, cacheVal);
            sum += val;
        }
        System.out.println(sum);


    }

}
