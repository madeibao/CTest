package com.sf.ccmas.video.config.odd.od18;

import java.util.Arrays;
import java.util.Scanner;

/**
 * 获取最大软件版本号
 * 知识点排序字符串
 * 时间限制:1s 空间限制: 256MB 限定语言:不限
 * 题目描述:
 * Maven版本号定义，<主版本>.<次版本><增量版本>-<里程碑版本>
 * 举例3.1.4-beta 其中，主版本和次版本都是必须的，主版本，次版本，增量版本由多位数字组成，可能包含前导零，里程碑版本由字符串组成。
 * <主版本>.<次版本>增量版本>:基于数字比较
 * 里程碑版本:基于字符串比较,采用字典序
 * 比较版本号时，按从左到右的顺序依次比较。基于数字比较，只需比较忽略任何前导零后的整数值
 * 输入2个版本号，输出最大版本号
 *
 * 输入描述
 * 输入2个版本号，换行分割，每个版本的最大长度小于50
 * 输出描述:
 * 版本号相同时输出第一个输入版本号
 * 补充说明:
 * 主版本，次版本，增量版本:
 * 基于字符串比较,比如
 * 1.5>1.4>1.3.11>1.3.9
 * 里程碑版本:基于字符串比较 比如
 * 1.2-beta-3>1.2-beta-11
 *
 * 示例1输入:
 * 2.5.1-C
 * 1.4.2-D
 * 输出:
 * 2.5.1-C
 * 说明:
 * 主版本，数字2大于1
 *
 * 示例2
 * 输入:
 * 1.3.11-S2
 * 1.3.11-S13
 * 输出:
 * 1.3.11-S2
 * 说明:
 * 里程碑版本，S2大于S13
 *
 * 示例3
 * 输入:
 * 1.05.1
 * 1.5.01
 * 输出:
 * 1.05.1
 * 说明:
 * 版本号相同，输出第一个版本号
 *
 * 示例4
 * 输入:
 * 1.5
 * 1.5.0
 * 输出:
 * 1.5.0
 * 说明:
 * 主次相同，存在增量版本大于不存在
 *
 * 解题思路: 逐个比较各个版本段的值，输出版本大的
 * 如果，最终数字是相同的
 * 如果主次相同，存在增量版本大于不存在, 输出增量的
 * 版本号相同时输出第一个输入版本号
 *
 */

public class Main {
    public static void main(String[] args) {
//        String aa = "1.5.0";
//        String[] strings = aa.split("\\.");
//        System.out.println(Arrays.asList(strings));


        Scanner sc = new Scanner(System.in);
        String line1 = sc.nextLine();
        String line2 = sc.nextLine();
        String[] v1Arr = line1.split("\\.");
        int len1 = v1Arr.length;

        String[] v2Arr = line2.split("\\.");
        int len2 = v2Arr.length;

        int len = Math.min(len1, len2);
        for (int i = 0; i < len; i++) {
            int intV1 = getIntVal(v1Arr[0]);
            int intV2 = getIntVal(v2Arr[0]);
            if (intV1 == intV2) {
                continue;
            }
            if (intV1 > intV2) {
                System.out.println(line1);
            }else {
                System.out.println(line2);
            }
            return;
        }
        //如果走到这里，说明数字版本号相同，如果主次相同，存在增量版本大于不存在, 版本号相同时输出第一个输入版本号
        if (len1 >= len2) {
            System.out.println(line1);
        } else {
            System.out.println(line2);
        }
    }


    //根据传入的版本段的字符串，获取一个int值，如果都是0，比如000，返回0；001返回1
    public static int getIntVal(String val) {
        //先比较主版本，先剔除掉前导0
        boolean hasZero = val.contains("0");
        int notZeroIndex = -1;
        if (hasZero) {
            char[] array = val.toCharArray();
            for (int i = 0; i < array.length; i++) {
                if (array[i] == 0) {
                    continue;
                }else {
                    //找到不为0的下标，立马退出
                    notZeroIndex = i;
                    break;
                }
            }
        }
        int num;
        //如果还是-1，则说明都是0
        if (notZeroIndex == -1) {
            num = 0;
        }else {
            String substring = val.substring(notZeroIndex);
            num = Integer.parseInt(substring);
        }
        return num;
    }



}

