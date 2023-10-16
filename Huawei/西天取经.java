


import java.util.Scanner;

/**
 * @Author 
 * @Date 2023/5/7 12:20
 */
public class 西天取经 {
    public static int[][] dis = new int[][] {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    public static int res = Integer.MAX_VALUE;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int m = in.nextInt();
            int n = in.nextInt();
            int k = in.nextInt();

            int[][] arr = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    arr[i][j] = in.nextInt();
                }
            }
            res = Integer.MAX_VALUE;

            for (int i = 0; i < dis.length; i++) {
                boolean[][] used = new boolean[m][n];
                used[0][0] = true;
                dfs(arr, dis[i][0], dis[i][1], k, 1, used, 3);
            }

            if (res == Integer.MAX_VALUE) {
                System.out.println(-1);
            } else {
                System.out.println(res);
            }
        }
    }

    public static void dfs(int[][] arr, int i, int j, int k, int sum, boolean[][] used, int bf) {
        int m = arr.length;
        int n = arr[0].length;
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }
        // 到达右下角
        if (i == m - 1 && j == n - 1) {
            // 取移动步数最小的结果
            res = Math.min(res, sum);
            return;
        }

        used[i][j] = true;

        // 分别遍历四个方向
        for (int l = 0; l < dis.length; l++) {
            int newI = i + dis[l][0];
            int newJ = j + dis[l][1];
            if (newI < 0 || newI>= m || newJ < 0 || newJ >= n) {
                continue;
            }
            if (used[newI][newJ]) {
                continue;
            }
            if (Math.abs(arr[i][j] - arr[newI][newJ]) <= k) {
                dfs(arr, newI, newJ, k, sum + 1, used, bf);
            } else {
                if (bf == 0) {  // 爆发次数用完了
                    continue;
                }
                dfs(arr, newI, newJ, k, sum + 1, used, bf - 1);
            }
        }
        used[i][j] = false;
    }
}

