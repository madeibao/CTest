package com.sf.ccmas.video.config.odd.od2;

import java.util.*;

// 题目描述
//         【停车场车辆统计】
//         特定大小的停车场，数组cars[]表示，其中1表示有车，0表示没车。
//         车辆大小不一，小车占一个车位（长度1），货车占两个车位（长度2），卡车占三个车位（长度3）。
//         统计停车场最少可以停多少辆车，返回具体的数目。
//         输入描述
//         整型字符串数组cars[]，其中1表示有车，0表示没车，数组长度小于1000。
//         输出描述
//         整型数字字符串，表示最少停车数目。
//
//         示例1   输入输出示例仅供调试，后台判题数据一般不包含示例
//
//         输入
//         1,0,1
//         输出
//         2
//         说明
//         1个小车占第1个车位
//         第二个车位空
//
//         1个小车占第3个车位
//         最少有两辆车
//
//         示例2   输入输出示例仅供调试，后台判题数据一般不包含示例
//
//         输入
//         1,1,0,0,1,1,1,0,1
//         输出
//         3
//
//         说明
//
//         1个货车占第1、2个车位
//         第3、4个车位空
//         1个卡车占第5、6、7个车位
//         第8个车位空
//         1个小车占第9个车位
//         最少3辆车


//这道题，可以使用双指针
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String[] split = s.split(",");
        //使用双指针
        int sum = 0;
        int temp = 0;
        for (int i = 0; i < split.length; i++) {
            if (Integer.parseInt(split[i]) == 1) {
                temp++;
            } else {
                if (temp > 0) {
                    int calculate = calculate(temp);
                    sum += calculate;
                    //计算完后记得清零
                    temp = 0;
                }

            }
        }
        //最后一个也要处理
        sum += calculate(temp);
        ;
        System.out.println(sum);


    }

    public static int calculate(int temp) {
        int total = 0;
        while (temp >= 3) {
            temp -= 3;
            total++;
        }
        while (temp >= 2) {
            temp -= 2;
            total++;
        }
        if (temp == 1) {
            total++;
        }
        return total;

    }

    public static int getSum(int n) {
        int[] dp = new int[n + 1];
        if (n == 0) {

            return 0;
        }
        if (n == 1 || n == 2) {
            return 1;
        }
        //初始化
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 3];
            System.out.println("i=" + i + " dp[i]=" + dp[i]);
        }
        return dp[n];
    }
}
