


import java.util.Scanner;

public class FristExam {
    public static int res = 0;
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        dfs (N, 1, 0);  // 1表示答的题目，0表示错误的个数
        System.out.println(res);
    }
    public static void dfs(int target, int i, int wrong) {
        if (target == 0) {
            res++;
            return;
        }
        if (i > 25 || wrong >= 3) {
            return;
        }
        if (i <= 10) {  // 选择题
            dfs (target - 2, i + 1, wrong);  // 答对
            dfs (target, i + 1, wrong + 1);  // 答错
        } else if (i <= 20) { // 判断题
            dfs (target - 4, i + 1, wrong);
            dfs (target, i + 1, wrong + 1);
        } else { // 多选题
            dfs (target - 8, i + 1, wrong);
            dfs (target, i + 1, wrong + 1);
        }
    }
}
