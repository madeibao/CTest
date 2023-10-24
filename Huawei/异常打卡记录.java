
输入：2
     100000,10,1,ABCD,ABCD
     100001,80,10,ABCE,ABCE
输出：null
说明：无异常打卡记录，所以返回null。

```java
package com.darling.boot.order.od.od14;

import java.util.*;


//
//如果出现以下两种情况，则认为打卡异常：
//* 实际设备号与注册设备号不一样。
//* 或者，同一个员工的两个打卡记录的时间小于60分钟并且打卡距离超过5km。

/**
 * 解题思路：
 * 这道题记得是 返回其中异常的打卡记录（按输入顺序输出），
 * 按顺序的话，必须记住对应的下标，存放的时候，就不能用单纯的set，list等等，就得用到map了
 * 然后异常的结果集 exceptionMap必须按照value进行升序排序后的放入list里面
 * 然后输出结果
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String numStr = sc.nextLine();
        int n = Integer.parseInt(numStr);

        Map<String, Integer> exceptionMap = new HashMap<>();
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            String line = sc.nextLine();

            String[] curStrings = line.split(",");
            int curTime = Integer.parseInt(curStrings[1]);
            int curDistance = Integer.parseInt(curStrings[2]);
            if (!curStrings[3].equals(curStrings[4])) {
                exceptionMap.put(line, i);
            }
            //和前面已有的对比，看能不能再找出异常的来
            for (String str: map.keySet()) {
                String[] split = str.split(",");
                int time = Math.abs(Integer.parseInt(split[1]) - curTime);
                int distance = Math.abs(Integer.parseInt(split[2]) - curDistance);
                if (time < 60 && distance > 5) {
                    exceptionMap.put(str, map.get(str));
                    exceptionMap.put(line, i);
                }
            }
            map.put(line, i);
        }
        if (exceptionMap.size() == 0) {
            System.out.println("null");
            return;
        }
        List<Map.Entry<String, Integer>> list = new ArrayList<>(exceptionMap.entrySet());
        list.sort((a1, a2) -> a1.getValue() - a2.getValue());
        StringBuilder sb = new StringBuilder();
        for (Map.Entry<String, Integer> entry : list) {
            sb.append(entry.getKey()).append(";");
        }
        //删掉最后一个 “;”
        sb.deleteCharAt(sb.length() - 1);
        System.out.println(sb);

    }


}

