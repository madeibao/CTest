


package com.darling.boot.order.od.od27;


import java.util.*;


/**
 * 知识图谱新词挖掘1
 *
 * 知识点滑窗
 * 时间限制: 1s 空间限制: 256MB 限定语言: 不限
 * 题目描述:
 * 小华负责公司知识图谱产品，现在要通过新词挖掘完善知识图谱。
 * 新词挖掘: 给出一个待挖掘文本内容字符串Content和一个词的字符串word，找到content中所有word的新词.
 * 新词: 使用词word的字符排列形成的字符串。
 * 请帮小华实现新词挖掘，返回发现的新词的数量。
 *
 * 输入描述:
 * 第一行输入为待挖掘的文本内容content;
 * 第二行输入为词word;
 *
 * 输出描述
 * 在中找到的所有word的新词的数量
 *
 * 补充说明:
 * 0<=content的长度<=10000000:
 * 1=<word的长度<=2000
 *
 * 示例1
 * 输入:
 * qweebaewqd
 * qwe
 * 输出:
 * 2
 *
 * 说明:
 * 起始索引等于 0 的子串是"qwe”它是 word的新词。
 * 起始索引等于 6 的子串是"ewq”,它是 word 的新词
 *
 * 示例2
 * 输入:
 * abab
 * ab
 * 输出:
 * 3
 * 说明:
 * 起始索引等于 0 的子串是"ab” 它是 word的新词
 * 起始索引等于 1 的子串是“ba",它是 word的新词
 * 起始索引等于 2 的子串是“ab”,它是 word的新词
 *
 * 解题思路：
 * 这个是标准的滑动窗口
 * 先对word进行字符排序
 * 然后滑动窗口，对截取的字符串进行字符排序，得出的排序后的substring，与排序后的word比较，想通就对结果集+1
 *
 *
 */

//输入:
//* qweebaewqd
//* qwe
//* 输出:
//* 2


import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String content = sc.nextLine();
        String word = sc.nextLine();

        //对word进行排序，获得排序后的字符串
        char[] wordArray = word.toCharArray();
        Arrays.sort(wordArray);
        String sortedWord = String.valueOf(wordArray);
        int wordLen = word.length();

        int count = 0;
        if (content.length() < wordLen) {
            System.out.println(count);
            return;
        }
        //注意边界值
        for (int i = 0; i <= content.length()-wordLen; i++) {
            int j = i + wordLen;
            String substring = content.substring(i, j);
            char[] chars = substring.toCharArray();
            Arrays.sort(chars);
            String sortedSubstring = String.valueOf(chars);
            if (sortedSubstring.equals(sortedWord)) {
                count++;
            }
        }
        System.out.println(count);
    }

}
