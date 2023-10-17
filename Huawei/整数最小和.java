

bb12-34aa

结果：
-31

1+2+(-34) = -31
——————————————————————————————————————————————————————————————————————
bb1234aa

结果
10 
——————————————————————————————————————————————————————————————————————

import java.util.*;

public class IntegerMinSum {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        char[] ch = str.toCharArray();
        int sum = 0;
        boolean flag = false; // 负数
        StringBuilder sb = new StringBuilder();

        for (char c : ch) {
            if (c >= '0' && c <= '9') {  // 如果是数字
                if (flag) {  // 如果是负号后面的数字，加到sb中
                    sb.append(c);
                } 
                else {  // 正数直接求和
                    sum += Integer.parseInt(c + "");
                }
            } else if ('-' == c) {  // 如果是'-'
                if (flag) {
                    if (!sb.toString().isEmpty()) {  // 遇到负号后，将负号后面的连续数字组成字符串
                        sum -= Integer.parseInt(sb.toString());  // 如果sb不空
                        sb = new StringBuilder();
                    }
                }
                flag = true;
            } else {  // 其它字符
                flag = false;  // 用来判断负号后的字符串结束
                if (!sb.toString().isEmpty()) {  // 队列不空，说明负号字符串到此为止，将去整体
                    sum -= Integer.parseInt(sb.toString());
                    sb = new StringBuilder();
                }
            }
        }
        
        if (flag) {
            if (!sb.toString().isEmpty()) {
                sum -= Integer.parseInt(sb.toString());
            }
        }
        System.out.print(sum);
    }
}
