



输入

2
hllo
FORWARD 1
INSERT e


输出
hello




1
hello
REPLACE HELLO_WORLD


输出：
HELLO_WORLD


import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String s = scanner.next();
        int[] a = new int[10];
        for (char c : s.toCharArray()) { // 记录0~9出现的次数
            a[c - '0']++;
        }
        int len = scanner.nextInt();
        int[] b = new int[10];
        for (int i = 1, l = 1; i <= 1000; i++) { // 右指针递增
            for (char c : String.valueOf(i).toCharArray()) {
                b[c - '0']++;
            }
            int tot = 0;
            for (int j = 0; j <= 9; j++) {
                while (b[j] > a[j]) { // 出现b数组中的个数大于a数组中的个数
                    for (char c : String.valueOf(l++).toCharArray()) { // 左指针递增
                        b[c - '0']--;
                    }
                }
                if (b[j] == a[j]) tot++;
            }
            if (tot == 10 && i - l + 1 == len) {
                System.out.println(l);
                break;
            }
        }
    }
}
