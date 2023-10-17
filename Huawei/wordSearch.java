


import java.util.Scanner;

public class wordSearch {
    public static boolean find = false;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int m = in.nextInt();
        int n = in.nextInt();
        in.nextLine();
        String word = in.nextLine();
        char[][] board = new char[m][n];
        for (int i = 0; i < m; i++) {
            String str = in.nextLine();
            for (int j = 0; j < n; j++) {
                board[i][j] = str.charAt(j);
            }
        }
        // 回溯DFS
        boolean[][] visited = new boolean[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word.charAt(0)) {
                    dfs (i, j, board, word, visited, 0);
                    if (find) {
                        System.out.print(i + 1);
                        System.out.print(" ");
                        System.out.print(j + 1);
                        return;
                    }
                }
            }
        }
        System.out.print("NO");
    }
    public static void dfs(int i, int j, char[][] board, String word, boolean[][] visited, int pos) {
        int m = board.length, n= board[0].length;
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j] || find || board[i][j] != word.charAt(pos)) {
            return;
        }
        if (pos == word.length() - 1) {
            find = true;
            return;
        }
        visited[i][j] = true;  // 修改当前状态
        dfs(i + 1, j, board, word, visited, pos + 1);
        dfs(i - 1, j, board, word, visited, pos + 1);
        dfs(i, j + 1, board, word, visited, pos + 1);
        dfs(i, j - 1, board, word, visited, pos + 1);
        visited[i][j] = false; // 撤销修改
    }
}
