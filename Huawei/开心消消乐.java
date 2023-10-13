


import java.util.Scanner;


public class 开心消消乐 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int n = in.nextInt();
            int m = in.nextInt();
            int[][] arr = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    arr[i][j] = in.nextInt();
                }
            }

            int res = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (arr[i][j] == 1) {
                        infect(arr, i, j);
                        res++;
                    }
                }
            }

            System.out.println(res);

        }
    }

    public static void infect(int[][] arr, int x, int y) {
        if(x < 0 || y < 0 || x >= arr.length || y >= arr[0].length || arr[x][y] != 1) {
            return;
        }
        arr[x][y] = 0;  // 感染的过程
        infect(arr, x + 1, y);  // 向下
        infect(arr, x - 1, y);  // 向上
        infect(arr, x, y + 1);  // 向右
        infect(arr, x, y - 1);  // 向左
        infect(arr, x + 1, y - 1);  // 向左下
        infect(arr, x + 1, y + 1);  // 向右上
        infect(arr, x + 1, y + 1);  // 向右下
        infect(arr, x - 1, y + 1);  // 向左上
    }
}
