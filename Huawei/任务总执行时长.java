package com.darling.boot.order.od.od10;

import com.sun.org.apache.bcel.internal.generic.IF_ACMPEQ;

import java.util.*;

/**
 * 任务总执行时长
 * 知识点 数组循环Q 递归时间限制: 1s 空间限制: 256MB 限定语言: 不限
 * 题目描述:
 * 任务编排服务负责对任务进行组合调度。参与编排的任务有两种类型，其中一种执行时长为taskA，另一种执行时长为taskB。
 * 任务一旦开始执行不能被打断，且任务可连续执行。服务每次可以编排num个任务。请编写一个方法，生成每次编排后的任务所有可能的总执行时长。
 *
 * 输入描述:
 * 第1行输入分别为第1种任务执行时长taskA，第2种任务执行时长taskB，这次要编排的任务个数num，以逗号分隔。
 * 输出描述:
 * 数组形式返回所有总执行时时长，需要按从小到大排列
 * 补充说明:
 * 每种任务的数量都大于本次可以编排的任务数量
 * 0 < taskA
 * 0 < taskB
 * 0 <= num <= 100000
 *
 * 示例1
 * 输入:
 * 1,2,3
 * 输出:
 * [3, 4, 5, 6]
 * 说明:
 * 可以执行 3次 taskA，得到结果 3; 执行 2次 taskA和 1次 taskB，得到结果 4。以此类推，得到最终结果.
 *
 * 解题思路:
 * 算法一:
 * 题目规定了只有两个任务taskA和taskB，所以可以直接用一层for循环就能搞定，然后对结果用treeset进行存放，这样就自动排序和去重
 * 如例1所示:1,2,3
 * 有3(num+1)种方式:
 * A,A,A 时长1+1+1=3;
 * A,A,B 时长1+1+2=4;
 * A,B,B 时长1+2+2 =5;
 * B,B,B 时长2+2+2=6;
 * 结果为3,4,5,6
 *
 *
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String[] split = line.split(",");
        int taskA = Integer.parseInt(split[0]);
        int taskB = Integer.parseInt(split[1]);
        int num = Integer.parseInt(split[2]);

        Set<Integer> set = new TreeSet<>();
        for (int i = 0; i <= num; i++) {
            int val = taskA * i + taskB * (num - i);
            set.add(val);
        }
        System.out.println(set);
//        System.out.println(new ArrayList<>(set));


    }
}

