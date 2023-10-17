


import java.util.Arrays;
import java.util.Scanner;

/**
 * @Author 
 * @Date 2023/6/11 15:15
 */
public class 篮球比赛 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int[] array = Arrays.stream(in.nextLine().split(" "))
                    .mapToInt(Integer::parseInt).toArray();

            int totalSum = 0;
            for (int arr : array) {
                totalSum += arr;
            }

            // 从0开始找最小差值战斗力
            for (int i = 0; i <= totalSum; i++) {
                int target = (totalSum - i);
                if (target % 2 == 0) {  // 总和减去差值可以被平分为两组
                    if (dfs(array, 0, target / 2, new boolean[10])) {
                        System.out.println(i);  // 能匹配则输出
                        break;
                    }
                }
            }

        }
    }

    // 回溯 遍历搜索分配球员
    public static boolean dfs(int[] array, int startIndex, int sum, boolean[] used) {
        if (startIndex > 5 || sum < 0) {
            return false;
        }
        if (startIndex == 5 && sum == 0) {
            return true;
        }

        for (int i = 0; i < array.length; i++) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            if (dfs(array, startIndex + 1, sum - array[i], used)) {
                return true;
            }
            used[i] = false;  // 回溯 不选
        }
        return false;
    }
}
