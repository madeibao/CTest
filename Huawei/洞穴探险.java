

import java.util.ArrayList;
import java.util.Scanner;

/**
 * @Author 马远
 */
public class Main {

    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        String str = cin.nextLine();
        cin.close();
        char[] chars = str.toCharArray();
        int max = 0;
        String ans = "(0,0)";

        ArrayList<Integer> left = new ArrayList<>();
        ArrayList<Integer> right = new ArrayList<>();
        for (int i = 0; i < chars.length; i++) {
            if (chars[i] == '(') {
                left.add(i);
            }
            if (chars[i] == ')') {
                right.add(i);
            }
        }

        for (int i = 0; i < left.size(); i++) {
            String[] strs = str.substring(left.get(i) + 1, right.get(i)).split(",");
            if (strs[0].charAt(0) != '0' && strs[1].charAt(0) != '0') {
                int x = Integer.parseInt(strs[0]),
                        y = Integer.parseInt(strs[1]),
                        distance = x * x + y * y;
                if (x < 1000 && y < 1000 && distance > max) {
                    max = distance;
                    ans = String.format("(%s,%s)", x, y);
                }
            }
        }

        System.out.println(ans);
    }
}