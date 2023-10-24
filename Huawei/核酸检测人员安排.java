

import java.util.*;

public class My {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        String[] strings = str.split(" ");
        //采集人员人数
        int nurseNum = Integer.parseInt(strings[0]);
        //志愿者人数
        int volunteerNum = Integer.parseInt(strings[1]);

        String line = sc.nextLine();
        String[] effStrArr = line.split(" ");
        //每个采集员的效率
        int[] eff = new int[nurseNum + 1];
        for (int i = 0; i < nurseNum; i++) {
            eff[i] = Integer.parseInt(effStrArr[i]);
        }
        //动态规划的方程
        int[][] dp = new int[nurseNum + 1][volunteerNum + 1];


        for (int i = 1; i <= nurseNum; i++) {
            for (int j = 0; j <= volunteerNum; j++) {
                //当前人员（第i个采集人员）的效率，因为eff是从0开始，所以要减1
                int curEff = eff[i - 1];
                int M = (int) (0.1 * curEff);
                //最开始， dp[i][j] 取值为 当前采集员(第i个采集员)，没有志愿者协助
                dp[i][j] = dp[i - 1][j] + curEff - 2 * M;
                if (j >= 1) {
                    //有 1 个志愿者协助当前采集员
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + curEff);
                }
                if (j >= 2) {
                    //有 2 个志愿者协助当前采集员
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 2] + curEff + M);
                }
                if (j >= 3) {
                    //有 3 个志愿者协助当前采集员
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 3] + curEff + 2 * M);
                }
                if (j >= 4) {
                    //有 4 个志愿者协助当前采集员
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 3] + curEff + 3 * M);
                }

            }
        }

//        for (int i = 0; i <= nurseNum; i++) {
//            for (int j = 0; j <= volunteerNum; j++) {
//                System.out.print(dp[i][j] + "\t");
//            }
//            System.out.println();
//        }

        System.out.println(dp[nurseNum][volunteerNum]);

    }


}
