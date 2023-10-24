package com.darling.boot.order.od.od9;

import com.sun.org.apache.bcel.internal.generic.IF_ACMPEQ;

import java.util.*;

/**
 * 投篮大赛
 *
 * 知识点字符串
 * 时间限制: 1s 空间限制: 256MB 限定语言: 不限
 * 题目描述:
 * 你现在是一场采用特殊赛制投篮大赛的记录员。这场比赛由若于回合组成，过去几回合的得分可能会影响以后几回合的得分
 * 比赛开始时，记录是空白的。你会得到一个记录操作的字符串列表 ops，其中 ops[i] 是你需要记录的第i项操作，
 * ops 遵循下述规则:
 * 整数 x - 表示本回合新获得分数 x
 * "+” - 表示本回合新获得的得分是前两次得分的总和
 * "D" -表示本回合新获得的得分是前一次得分的两倍
 * "C" -表示本回合没有分数，并且前一次得分无效，将其从记录中移除
 * 请你返回记录中所有得分的总和。
 *
 * 输入描述:
 * 输入为一个字符串数组
 * 输出描述:
 * 输出为一个整形数字
 * 提示:
 * 1、1 <= ops.length <= 1000
 * 2、opsli] 为”C”、"D”、"+”，或者一个表示整数的字符串。整数范围是[-3* 10^4,3* 104]
 * 3、需要考虑异常的存在，如有异常情况，请返回-1:
 * 4、对于“+”操作，题目数据不保证记录此操作时前面总是存在两个有效的分数
 * 5、对于“C”和”D”操作，题目数据不保证记录此操作时前面存在一个有效的分数
 * 6、题目输出范围不会超过整型的最大范围，不超过2^63-1
 *
 * 示例 1:
 * 输入:
 * 5 2 C D +
 * 输出:
 * 30
 *
 * 解释:
 * "5” - 记录加 5，记录现在是[5]
 * "2” - 记录加2，记录现在是[5,2]
 * "C” - 使前一次得分的记录无效并将其移除，记录现在是[5].
 * "D” - 记录加 2*5= 10 ，记录现在是[5,10].
 * "+" - 记录加 5+10 =15，记录现在是[5,10,15].
 * 所有得分的总和 5 + 10 + 15 = 30
 *
 * 示例 2:
 * 输入:
 * 5 -2 4 C D 9 + +
 * 输出:
 * 27
 *
 * 解释:
 * "5” - 记录加 5，记录现在是[5]
 * "-2” - 记录加-2，记录现在是[5,-2]
 * "4” - 记录加 4，记录现在是[5,-2,4]
 * "C" - 使前一次得分的记录无效并将其移除，记录现在是[5-2]
 * "D” - 记录加 2*-2=-4 ，记录现在是[5,-2,-4]
 * "9" - 记录加 9，记录现在是[5,-2,-4,9]
 * "+" - 记录加-4 +9=5，记录现在是[5,-2,-4,9,5]
 * "+" - 记录加9+5=14 ，记录现在是[5,-2,-4,9,5,14]
 * 所有得分的总和5+-2+-4+9+5+14=27
 *
 * 示例 3:
 * 输入:
 * 1
 * 输出:
 * 1
 *
 * 示例 4:
 * 输入:
 * +
 * 输出:
 * -1
 *
 * 解题思路:
 * 简单的逻辑题，需要注意:
 * 1. 处理C和D是集合长度需要大于0
 * 2. 处理+的时候集合长度需要大于1
 * 为了提高性能，可以使用双端队列 deque， 在"+"的时候要注意一下
 *
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String[] split = line.split(" ");
        String unDigit = "CD+";
        Deque<Integer> list = new LinkedList<>();
        for (String str : split) {
            //如果是非数字，分情况讨论
            if (unDigit.contains(str)) {
                //如果list里元素的个数为0，直接跳出循环
                if (list.size() == 0) {
                    System.out.println(-1);
                    break;
                }
                if ("C".equals(str)) {
                    list.removeLast();
                } else if ("D".equals(str)) {
                    Integer last = list.getLast();
                    list.addLast(last * 2);
                } else if ("+".equals(str)) {
                    //此时，list元素个数必须大于等于2，至少有两个元素
                    if (list.size() < 2) {
                        System.out.println(-1);
                        break;
                    }
                    //当前队列的尾部
                    Integer last = list.pollLast();
                    //尾部的前一个
                    Integer preLast = list.pollLast();
                    //使用"+"元素后，新的尾部
                    Integer curLast = preLast + last;
                    list.add(preLast);
                    list.add(last);
                    list.add(curLast);
                }
            }else {
                list.add(Integer.parseInt(str));
            }
        }

        int sum = 0;
        for (int num: list) {
            sum += num;
        }
        System.out.println(sum);


    }
}

