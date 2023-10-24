package com.AAAA.www;

六、效果展示
1、输入
[“javanezha”,“pythonnezha”,“cnezha”]

2、输出
nezha





import java.util.Scanner;

/**
 * @Author 马远
 */

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] arr = sc.nextLine().replace("[", "").replace("]", "").replace("\"", "").split(",");
        StringBuilder builder = new StringBuilder();// 通过第一个作为参考字符串，与其它字符串比较
        String firstStr = arr[0];// 遍历第一个字符串
        for (int i = 0; i < firstStr.length(); i++) {// 最后一个字符，倒取比较
            char c = firstStr.charAt(firstStr.length() - i - 1);// 通过第一个作为参考字符串，与其它字符串比较，所以此处略过第一个字符串
            for (int j = 1; j < arr.length; j++) {// 其它字符串
                String str = arr[j];// 如果长度不满足 or 字符不一致，结束循环
                if (str.length() <= i || c != str.charAt(str.length() - i - 1)) {
                    // 输出最长公共后缀，因为倒序遍历添加，所以要反转一下
                    System.out.println(builder.length() == 0 ? "@Zero" : builder.reverse());
                    return;
                }
            }
            builder.append(c);
        }// 输出最长公共后缀，因为倒序遍历添加，所以要反转一下
        System.out.println(builder.length() == 0 ? "@Zero" : builder.reverse());
    }
}


