

import java.util.Scanner;

public class  Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String act = cin.nextLine();
        cin.close();
        // 初始数据，本题的关键，按照输出顺序，构建左右，前后，上下序列
        int[][] sz = {
                {1, 2}, // 左右
                {3, 4}, // 前后
                {5, 6} // 上下
        };
        // L: 左翻 (左右互换；上下，左右互换)
        /**
         {
         {5,6},
         {3,4},
         {2,1}
         }
         */
        // R: 右翻（上下互换；上下，左右互换）
        /**
         {
         {6,5},
         {3,4},
         {1,2}
         }
         */
        // F: 前翻（前后互换；前后，上下互换）
        /**
         {
         {1,2},
         {5,6}
         {4,3}
         }
         */
        // B: 后翻 （上下互换；前后，上下互换）
        /**
         {
         {1,2},
         {6,5},
         {3,4}
         }
         */
        // A: 逆时针旋转90（前后互换；左右，前后互换）
        /**
         {
         {4,3},
         {1,2},
         {5,6}
         }
         */
        // C: 顺时针旋转90 （左右互换；左右，前后互换）
        /**
         {
         {3,4},
         {2,1},
         {5,6}
         }
         */

        // FCR
        // F {{1,2},{5,6}{1,2}}

        for (char c : act.toCharArray()) {
            if (c == 'L' || c == 'R') {
                if (c == 'L') {
                    int x = sz[0][0], y = sz[0][1];
                    sz[0][0] = y;
                    sz[0][1] = x;
                } else if (c == 'R') {
                    int x = sz[2][0], y = sz[2][1];
                    sz[2][0] = y;
                    sz[2][1] = x;
                }
                int[] p = sz[2];
                sz[2] = sz[0];
                sz[0] = p;
            }
            if (c == 'B' || c == 'F') {
                if (c == 'F') {
                    int x = sz[1][0], y = sz[1][1];
                    sz[1][0] = y;
                    sz[1][1] = x;
                } else if (c == 'B') {
                    int x = sz[2][0], y = sz[2][1];
                    sz[2][0] = y;
                    sz[2][1] = x;
                }
                int[] p = sz[1];
                sz[1] = sz[2];
                sz[2] = p;
            }
            if (c == 'A' || c == 'C') {
                if (c == 'A') {
                    int x = sz[1][0], y = sz[1][1];
                    sz[1][0] = y;
                    sz[1][1] = x;
                } else if (c == 'C') {
                    int x = sz[0][0], y = sz[0][1];
                    sz[0][0] = y;
                    sz[0][1] = x;
                }
                int[] p = sz[0];
                sz[0] = sz[1];
                sz[1] = p;
            }
        }

        int m = sz.length, n = sz[0].length;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                sb.append(sz[i][j]);
            }
        }

        System.out.println(sb);
    }
}