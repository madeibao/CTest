
import java.util.Scanner;
import java.util.*;


public class PerfactAlignment {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] wasd = sc.nextLine().toCharArray();
        int endStep = step(wasd);
        System.out.println(endStep);
    }
 
    public static int step(char[] wasd){
        //平均值
        int avg = wasd.length / 4;
        //统计修改修改的方向值
        int numA = 0;
        int numS = 0;
        int numW = 0;
        int numD = 0;
        for (int i = 0; i < wasd.length;i++){
            switch (wasd[i]){
                case 'A':
                    numA++;
                    break;
                case 'S':
                    numS++;
                    break;
                case 'W':
                    numW++;
                    break;
                case 'D':
                    numD++;
                    break;
            }
        }
        //绝对值（求出最大值 - 平均值）
        int step = Math.abs(Math.max(Math.max(Math.max(numA, numS), numW), numD) - avg);
        return step;
    }
}