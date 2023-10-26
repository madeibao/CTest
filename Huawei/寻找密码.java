

import java.util.*;

/**
 * 寻找密码
 *
 * 知识点树时间限制: 1s 空间限制: 32MB 限定语言: 不限
 * 题目描述:
 * 小王在进行游戏大闯关，有一个关卡需要输入一个密码才能通过。
 * 密码获得的条件如下:在一个密码本中，每一页都有一个由26个小写字母组成的若干位密码，每一页的密码不同，需要从这个密码本中寻找这样一个最长的密码，
 * 从它的未尾开始依次去掉一位得到的新密码也在密码本中存在。请输出符合该要求的密码，如果有多个符合要求的密码，则返回字典序最大的密码。
 * 若没有符合要求的密码，则返回空字符串。
 *
 * 输入描述:
 * 密码本由一个字符串数组组成，不同元素之间使用空格隔开，每一个元素代表密码本每一页的密码
 *
 * 输出描述:
 * 一个字符串
 *
 * 补充说明:
 * 1 <= 密码本的页数 <= 105
 * 1 <= 每页密码的长度 <= 105
 *
 * 示例1
 *
 * 输入:
 * h he hel hell hello
 * 输出:
 * hello
 *
 * 说明:
 * "hello"从未尾依次去掉一位得到的“hel"，"hel"，"he"和"h"在密码本中都存在
 *
 * 示例2
 *
 * 输入:
 * b eredderd bw bww bwwl bwwlm bwwln
 * 输出:
 * bwwln
 *
 * 说明:
 * "bwwim"和"bwwin"从未尾开始依次去掉一位得到密码在密码本中都存在。但是"bwwin"比"bwwim”字典序排序大，所以应该返回"bwwin"
 *
 * 解题思路: (注意字典序大小判断是 str.compareTo(res) 大于0，表示str的字典序比res的大 )
 * 1.将输入的密码本放在list中，主要是想用list的contains函数
 * 2.循环求出所有符合密码规则的字符串，取较长的字符串作为密码;如果字符串长度相等，则取字典序大的作为密码
 *
 *
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String[] split = line.split(" ");

        Set<String> set = new HashSet<>();
        for (String str : split) {
            set.add(str);
        }

        String res = "";
        for (String str : split) {
            //看str是否符合条件
            if (isAllSubStrExist(str, set)) {
                if (str.length() > res.length()) {
                    res = str;
                } else if (str.length() == res.length() && str.compareTo(res) > 0) {
                    res = str;
                }
            }
        }
        System.out.println(res);


    }

    public static boolean isAllSubStrExist(String str, Set<String> set) {
        for (int i = 1; i <= str.length(); i++) {
            String substring = str.substring(0, i);
            if (!set.contains(substring)) {
                return false;
            }
        }
        return true;
    }
}
