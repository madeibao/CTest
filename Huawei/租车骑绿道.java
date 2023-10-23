package com.darling.boot.order.od.od19;

import com.google.common.base.Strings;

import java.util.*;


/**
 * 租车骑绿道
 * <p>
 * 题目
 * 部门组织绿岛骑行团建活动。租用公共双人自行车骑行，每辆自行车最多坐两人、最大载重 M.
 * 给出部门每个人的体重，请问最多需要租用多少双人自行车。
 * 输入
 * 第一行两个数字 m、n，自行车限重 m，代表部门总人数 n。
 * 第二行，n 个数字，代表每个人的体重。体重都小于等于自行车限重 m.
 * 0<m <= 200
 * 0 < n <= 1000000
 * 输出
 * 最小需要的双人自行车数量.
 * <p>
 * 示例一
 * 输入
 * 3 4
 * 3 2 2 1
 * 输出
 * 3
 * <p>
 * 解题思路
 * 算法思想:
 * 输入自行车限重 m 和部门人数 n。
 * 输入每个人的体重，并将体重排序.
 * 设置双指针i和j，分别指向最小和最大体重的人。
 * 如果两人体重之和小于等于 m，则租一辆双人自行车。如果两人体重之和大于 m，则租一辆单人自行车.
 * 最后输出最少需要的自行车数量
 * 核心知识点
 * 代码简单，直接阅读理解即可
 * <p>
 * 解题思路，使用双指针
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line1 = sc.nextLine();
        String line2 = sc.nextLine();
        String[] split = line1.split(" ");
        int m = Integer.parseInt(split[0]);
        int n = Integer.parseInt(split[1]);
        int res = 0;

        String[] strings = line2.split(" ");
        int[] nums = new int[strings.length];
        for (int i = 0; i < nums.length; i++) {
            nums[i] = Integer.parseInt(strings[i]);
        }
        Arrays.sort(nums);
        int i = 0;
        int j = nums.length - 1;
        while (i < j) {
            //如果两个重量加起来大于m，那么右指针左移
            if (nums[i] + nums[j] > m) {
                j--;
                res++;
            } else {
                i++;
                j--;
                res++;
            }
        }
        //考虑特殊情况，左右指针相等时，
        if (i == j) {
            res++;
        }
        System.out.println(res);
    }
}
