
6 6
SBBBBB
BXXXXB
BBXBBB
XBBXXB
BXBBXB
BBXBEB


----------------
输出：
13



import java.util.Scanner;

/**
 * @Author
 * @Date 2023/5/6 23:46
 */
public class Soldier {
    static int[][] dir = new int[][] {{1, 0 ,1}, {-1, 0, 2}, {0, 1, 3}, {0, -1, 4}};
    static int res = Integer.MAX_VALUE;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int m = in.nextInt();
            int n = in.nextInt();
            in.nextLine();
            char[][] chars = new char[m][n];
            for (int i = 0; i < m; i++) {
                chars[i] = in.nextLine().toCharArray();
            }

            int si = 0;
            int sj = 0;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (chars[i][j] == 'S') {
                        si = i;
                        sj = j;
                        break;
                    }
                }
            }

            for (int i = 0; i < dir.length; i++) {
                boolean[][] used = new boolean[m][n];
                used[si][sj] = true;
                dfs(chars, si + dir[i][0], sj + dir[i][1], dir[i][2], 1, used);
            }
            if (res == Integer.MAX_VALUE) {
                System.out.println(-1);
            } else {
                System.out.println(res);
            }

        }
    }

    public static void dfs(char[][] chars, int i, int j, int direction, int count, boolean[][] user) {
        int m = chars.length;
        int n = chars[0].length;
        if (i < 0 || i >= m || j < 0 || j >= n || chars[i][j] == 'X') {
            return;
        }

        // 到达E 目的地
        if (chars[i][j] == 'E') {
            res = Math.min(res, count);
            return;
        }

        user[i][j] = true;
        
        // 分别遍历四个方向
        for (int k = 0; k < dir.length; k++) {
            int newI = i + dir[k][0];
            int newJ = j + dir[k][1];
            if (newI < 0 || newI >= m || newJ < 0 || newJ >= n ||
                    chars[newI][newJ] == 'X') {
                continue;
            }

            if (user[newI][newJ]) {
                continue;
            }

            if (dir[k][2] == direction) {  // 不改变方向
                dfs(chars, newI, newJ, dir[k][2], count + 1, user);
            } else {  // 改变方向
                dfs(chars, newI, newJ, dir[k][2], count + 2, user);
            }
        }
        user[i][j] = false;
    }
}
