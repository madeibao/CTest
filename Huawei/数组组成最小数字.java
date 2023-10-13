
数组组成的最小数字
描述
给定一个整型数组，请从该数组中选择 3 个元素组成最小数字并输出（如果数组
长度小于 3，则选择数组中所有元素来组成最小数字）

例一：

21,30,62,5,31
21305


例二：

5,21
215


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;


public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        while (sc.hasNext() ) {
            String[] str = sc.nextLine().split(",");
            int[] arr = new int[str.length];
            for (int i = 0 ; i < arr.length ; i++) {
                arr[i] = Integer.parseInt(str[i]);
            }
            Arrays.sort(arr);
            if (arr.length > 3) arr = Arrays.copyOf(arr, 3);

            String res = findLess(arr);
            System.out.println(res);
        }
    }

    public static String findLess(int[] arr) {
        List<String> list2 = new ArrayList<>();

        for(var i:arr) {
            list2.add(String.valueOf(i));
        }
        list2.sort((o1,o2)->(o1+o2).compareTo(o2+o1));
        StringBuilder sb = new StringBuilder();

        for(var i:list2)  {
            sb.append(i);
        }
        return sb.toString();
    }
}