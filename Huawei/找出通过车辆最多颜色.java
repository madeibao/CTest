

package com.darling.boot.order.od.od17;

import com.google.common.base.Strings;

import java.util.*;
 
//29 最多提取子串数目

/**
 * 最多提取子串数目
 * 题目
 * 在一个狭小的路口，每秒只能通过一辆车，假如车辆的颜色只有3种，找出N秒内经过的最多颜色的车辆数量 三种颜色编号为0,1,2
 * 输入描述：
 * 第一行输入的是通过的车辆颜色信息 [0,1,1,2] 代表4秒钟通过的车辆颜色分别是0,1,1,2
 * 第二行输入的是统计时间窗，整型，单位为秒
 *
 * 输出描述：
 * 输出指定时间窗内经过的最多颜色的车辆数量
 *
 * 示例1
 * 输入:
 * 0 1 2 1
 * 3
 *
 * 输出:
 * 2
 *
 * 说明:
 * 在[1,2,1]这个3秒时间窗内，1这个颜色出现2次，数量最多
 *
 * 示例2
 * 输入:
 * 0 1 2 1
 * 2
 * 输出:
 * 1
 *
 * 说明:
 * 在2秒时间窗内，每个颜色最多出现1次
 *
 * 解题思路：
 * 可以使用滑动窗口的方式
 *
 */
public class Main1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String str = sc.nextLine();
        int n = Integer.parseInt(str);
        String[] strings = line.split(" ");

        int[] nums = new int[3];

        int max = 0;
        //先初始化窗口，i相当于右指针，i-3相当于左指针
        for (int i = 0; i < strings.length; i++) {
            int color = Integer.parseInt(strings[i]);
            nums[color]++;
            if (i >= n) {
                //左指针，右指针-窗口大小
                int left = i - n;
                int leftColor = Integer.parseInt(strings[left]);
                nums[leftColor]--;
            }
            max = Math.max(nums[color], max);
        }
        System.out.println(max);

    }
}
