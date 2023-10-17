package com.AAAA.www;


// 输入	iwdvpbn,hk,iuop,iikd,kadgpf
// 输出	14
// 说明	
// 数组中有5个元素。

// iwdvpbn与hk无相同的字符，满足条件，iwdvpbn的长度为7，hk的长度为2，乘积为14（7*2）。

// iwdvpbn与iuop、iikd、kadgpf均有相同的字符，不满足条件。

// iuop与iikd、kadgpf均有相同的字符，不满足条件。

// iikd与kadgpf有相同的字符，不满足条件。

// 因此，输出为14。


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

