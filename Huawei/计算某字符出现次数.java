

import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String str1 = (sc.nextLine()).toLowerCase();
            char[] ch = str1.toCharArray();

            // 单个字符的输入
            String str2 = (sc.nextLine()).toLowerCase();
            char cr = str2.charAt(0);
            int count = 0;
            for (int i = 0 ; i < ch.length ; i++ ) {
                if (ch[i] == cr) {
                    count++;
                }
            }
            System.out.println(count);

        }
    }
}
