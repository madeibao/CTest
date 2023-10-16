
/**
 * @ClassName Main
 * @Author：Mayuan
 * @Date 2021/4/11/0011 20:56
 * @Description TODO
 * @Version 1.0
 * <p>
 * 在一些考试中，类的命名常常为 Main
 **/

import java.util.Scanner;

/**
 * @Author
 * @Date 2023/5/3 20:45
 */
public class Main {
    private static final int[][] directions = {{0, 1, 1}, {0, -1, 2}, {1, 0, 3}, {-1, 0, 4}};

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            // 处理输入
            int t = in.nextInt();
            int c = in.nextInt();

            int n = in.nextInt();
            int m = in.nextInt();


            char[][] chars = new char[n][m];
            for (int i = 0; i < n; i++) {
                String string = in.next();
                chars[i] = string.toCharArray();
            }

            int sX = 0;
            int sY = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (chars[i][j] == 'S') {
                        sX = i;
                        sY = j;
                        break;
                    }
                }
                if (chars[sX][sY] == 'S') {
                    break;
                }
            }

            boolean[][] used = new boolean[n][m];
            if (chars[sX][sY] == 'S') {
                if (dfs(chars, sX, sY, t, c, 0, used)) {
                    System.out.println("YES");
                } else {
                    System.out.println("NO");
                }
            } else {
                System.out.println("NO");
            }
        }
    }

    public static boolean dfs(char[][] chars, int x, int y, int t, int c, int dis, boolean[][] used) {
        int n = chars.length;
        int m = chars[0].length;
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return false;
        }
        if (chars[x][y] == 'T') {
            return true;
        }
        used[x][y] = true;
        for (int i = 0; i < directions.length; i++) {
            int newX = x + directions[i][0];
            int newY = y + directions[i][1];

            // 超过边界
            if (newX < 0 || newX >= n || newY < 0 || newY >= m || used[newX][newY]) {
                continue;
            }

            // 当前是障碍
            if (chars[newX][newY] == '*') {
                // 清除障碍数用完了
                if (c == 0) {
                    continue;
                }
                if (dis == 0 || dis == directions[i][2]) {
                    if (dfs(chars, newX, newY, t, c - 1, dis, used)) {
                        return true;
                    }
                }
                else {
                    // 上一步方向跟当前方向不一致
                    // 拐弯数用完
                    if (t == 0) {
                        continue;
                    }
                    if (dfs(chars, newX, newY, t - 1, c - 1, dis, used)) {
                        return true;
                    }
                }
            }
            else {
                if (dis == 0 || dis == directions[i][2]) {
                    if (dfs(chars, newX, newY, t, c, dis, used)) {
                        return true;
                    }
                } else {
                    if (t == 0) {
                        continue;
                    }
                    if (dfs(chars, newX, newY, t - 1, c, dis, used)) {
                        return true;
                    }
                }
            }
        }
        used[x][y] = false;
        return false;
    }

}

