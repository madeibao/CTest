

package com.sf.ccmas.video.config.odd.od3;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

/**
 * 猜字谜
 * 题目描述
 * 小王设计了一个简单的猜字谜游戏，游戏的谜面是一个错误的单词，比如nesw，玩家需要猜出谜底库中正确的单词。
 * 猜中的要求如下：
 * 对于某个谜面和谜底单词，满足下面任一条件都表示猜中：
 *
 * 变换顺序以后一样的，比如通过变换w和e的顺序，nwes跟news是可以完全对应的；
 * 字母去重以后是一样的，比如woood和wood是一样的，它们去重后都是wod
 * 请你写一个程序帮忙在谜底库中找到正确的谜底。
 * 谜面是多个单词，都需要找到对应的谜底，如果找不到的话，返回not found
 *
 * 输入描述
 * 谜面单词列表，以,分隔
 * 谜底库单词列表，以,分隔
 * 输出描述
 * 匹配到的正确单词列表，以,分隔
 * 如果找不到，返回not found
 *
 * 备注
 * 单词的数量N的范围： 0
 *
 * 输入：
 * conection
 * connection,today
 * 输出：
 * connection
 *
 * 示例：
 * 输入：
 * bdni,woooood
 * bind,wrong,wood
 *
 */

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String strUp = scanner.nextLine();
        String strDown = scanner.nextLine();
        String[] splitUp = strUp.split(",");
        String[] splitDown = strDown.split(",");
        Map<String, String> map = new HashMap<>();
        //将谜底先排序在去重，放在hashmap里面
        for (int i = 0; i < splitDown.length; i++) {
            String str = splitDown[i];
            char[] charArray = str.toCharArray();
            Arrays.sort(charArray);
            //下面是去重
            StringBuilder sb = new StringBuilder();
            for (int j = 1; j < charArray.length; j++) {
                if (charArray[j] == charArray[j - 1]) {
                    continue;
                }
                sb.append(charArray[j]);
            }
            map.put(sb.toString(), str);
        }

        //谜面，
        StringBuilder result = new StringBuilder();
        for (int i = 0; i < splitUp.length; i++) {
            String str = splitUp[i];
            char[] charArray = str.toCharArray();
            Arrays.sort(charArray);
            //下面是去重
            StringBuilder sb = new StringBuilder();
            for (int j = 1; j < charArray.length; j++) {
                if (charArray[j] == charArray[j - 1]) {
                    continue;
                }
                sb.append(charArray[j]);
            }
            String s = map.get(sb.toString());
            if (s != null) {
                result.append(s + ",");
            }
        }
        if (result.length() > 0) {
            String string = result.deleteCharAt(result.length() - 1).toString();
            System.out.println(string);
        }else {
            System.out.println();
        }

        return;
    }
}
