package com.AAAA.www;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**最大乘积
 * @author ASUS*/

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String input = scanner.nextLine();
        String wordArr[] = input.split(",");
        List<List<Character>> keySetList = new ArrayList<List<Character>>();
        for (String word : wordArr) {
            List<Character> cList = new ArrayList<Character>();
            for (char c : word.toCharArray()) {
                cList.add(c);
            }
            keySetList.add(cList);
        }
        // 这里是一个二维的字符矩阵列表
        System.out.println(keySetList);
        int start = 0;
        int end = 1;
        int max = 0;
        while (end < keySetList.size()) {
            List<Character> startList = keySetList.get(start);
            List<Character> endtList = keySetList.get(end);
            boolean flag = true;
            for (Character c : startList) {
                if (endtList.contains(c)) {
                    flag = false;
                    break;
                }
            }

            if (flag && max < startList.size() * endtList.size()) {
                max = startList.size() * endtList.size();
            }
            if (end == keySetList.size() - 1) {
                // 最后一位
                start++;
                end = start + 1;
            } else {
                end++;
            }
        }
        
        System.out.println(max);
    }
}

