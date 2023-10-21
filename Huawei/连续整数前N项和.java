

525 6

85 86 87 88 89 90

-----------------------------____________________________________--

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            int sum = sc.nextInt();
            int n = sc.nextInt();
            //an = a1 + (n -1) *d
            //Sn = (a1 + an) *n /2 此处d = 1
            //Sn = a1 * n + n * (n -1)/2
            //a1 = (Sn*2/n -n+1))/2
            int a = 0;
            if (sum * 2 % n != 0) {
                System.out.println(-1);
                return;
            }
            if ((sum * 2 / n - n) % 2 == 0) {
                System.out.println(-1);
                return;
            } else {
                a = (sum * 2 / n - n + 1) / 2;
                for (int i = 0 ; i < n ; i++) {
                    System.out.print(a + i);
                    System.out.print(" ");
                }
            }
        }
    }
}
