4
22220
00000
00000
11111



输出：

8
---------------------------------------------------------------------------

import java.util.Arrays;
import java.util.Scanner;



public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int n = Integer.parseInt(in.nextLine());
            int[][] array = new int[n][];
            for (int col = 0; col < n; col++) {
                array[col] = Arrays.stream(in.nextLine().split(""))
                        .mapToInt(Integer::parseInt).toArray();
            }

            int maxValue = 0;
            // int maxSum = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < array[i].length; j++) {
                    if (array[i][j] != 0) {
                        maxValue = Math.max(maxValue, dfs(array, i, j));
                    }
                }
            }

            System.out.println(maxValue);
        }
    }

    // 方法一：
    public static int dfs(int[][] array, int i, int j) {
        if (i < 0 || j < 0 || i >= array.length || j >= array[i].length || array[i][j] == 0) {
            return 0;
        }

        int sum = array[i][j];
        array[i][j] = 0;
        sum += dfs(array, i + 1, j);
        sum += dfs(array, i - 1, j);
        sum += dfs(array, i, j + 1);
        sum += dfs(array, i, j - 1);
        return sum;
    }
}
