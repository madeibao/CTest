

//拔河比赛


import java.util.Scanner;


public class Main {
    static int avg = 0;//
    static int[] tempNum = null;// 取到的数
    static int minCount = 0;
    static int nums[] = null;
    static int tempIndex[] = null;// 取了哪些索引

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = Integer.parseInt(sc.nextLine());
        nums = new int[num];
        int sum = 0;
        for (int i = 0; i < num; i++) {
            nums[i] = sc.nextInt();
            sum += nums[i];
        }
        if (sum % 2 != 0) {
            System.out.println(-1);
            System.exit(0);
        }
        avg = sum / 2;
        tempNum = new int[num];
        tempIndex = new int[num];
        for (int i = 0; i < num; i++) {
            tempIndex[i] = -1;
        }
        minCount = num;
        dfs(0, 0);
        System.out.println(minCount);
    }

    public static void dfs(int p, int count) {
        int tempSum = 0;
        for (int i = 0; i < count; i++) {
            tempSum += tempNum[i];
            if (tempSum == avg) {
                if (minCount > count) {
                    minCount = count;
                }
                break;
            }
            if (tempSum > avg) {
                // 超了
                return;
            }
        }
        for (int j = 0; j < nums.length; j++) {
            boolean flag = false;
            for (int k = 0; k <= count; k++) {
                if (tempIndex[k] == j) {
                    flag = true;
                    break;
                }
            }
            if (!flag) {
                tempNum[count] = nums[j];
                tempIndex[count] = j;
                dfs(p + 1, count + 1);
            }
        }
    }
}
