package com.darling.boot.order.od.od15;

import java.util.*;

/**
 * 最左侧 冗余覆盖子串
 * 知识点滑窗
 * 时间限制:1s 空间限制: 256MB 限定语言: 不限
 * 题目描述:
 * 给定2个字符串s1和s2和正整数k，其中s1长度为n1，s2长度为n2，在s2中选一个子串，满足:
 * 该子串长度为n1+k
 * 该子串包含s1中全部字母
 * 该子串每个字母的出现次数不小于s1中对应的字母
 * 我们称s2以长度k几余覆盖s1。给定s1、s2和k，求最左侧的s2以长度k几余覆盖s1的子串的首个元素的下标，如果没有返回-1
 * 举例:
 * s1=ab
 * s2=aabcd
 * k=1
 * 则子串aab和abc均满足此条件，由于aab在abc的左侧，aab的第一个元素下标为0，因此输出0
 * <p>
 * 输入描述:
 * 输入三行，第一行为s1，第二行为s2，第三行为k
 * s1和s2只包含小写字母
 * 输出描述:
 * 最左侧的s2以长度k冗余覆盖s1的子串首个元素的下标，如果没有返回-1
 * 补充说明:
 * 0<=len(s1)<=1000000
 * 0<=len(s2) <= 20000000
 * 0<=k<=1000
 * 示例1
 * 输入:
 * ab
 * aabcd
 * 1
 * 输出:
 * 0
 * <p>
 * 说明:
 * 子串aab和abc满足要求，由于aab在abc的左侧，因此输出aab的下下标:0
 * <p>
 * 示例2
 * 输入:
 * abc
 * dfs
 * 10
 * 输出:
 * -1
 * <p>
 * 说明:
 * s2无法覆盖s1，输出-1
 * <p>
 * 解题思路:
 * 1.通过s1的长度和k值计算出父字符串的长度
 * 2从s2遍历中截取步骤1的长度的字符串作为父字符串3通过双层for循环，求出s1是否为步骤2中的子串
 */

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s1 = sc.nextLine();
        String s2 = sc.nextLine();
        String numStr = sc.nextLine();
        int k = Integer.parseInt(numStr);
        int len = s1.length() + k;

        int len1 = s1.length();
        int len2 = s2.length();
        if (len2 < len) {
            System.out.println(-1);
            return;
        }
        for (int i = 0; i <= (len2 - len); i++) {
            String substring = s2.substring(i, i + len);
            if (substring.contains(s1)) {
                System.out.println(i);
                return;
            }
        }

        System.out.println(-1);

    }


}

