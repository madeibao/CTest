

package com.darling.boot.order.od.od26;


import java.util.*;


/**
 * 查找充电设备组合
 *
 * 题目描述
 * 某个充电站，可提供 n 个充电设备，每个充电设备均有对应的输出功率。
 * 任意个充电设备组合的输出功率总和，均构成功率集合 P 的 1 个元素。
 * 功率集合 P 的最优元素，表示最接近充电站最大输出功率 p_max 的元素。
 *
 * 输入描述
 * 输入为三行：
 * 第一行为充电设备个数 n。
 * 第二行为每个充电设备的输出功率。
 * 第三行为充电站最大输出功率 p_max。
 *
 * 输出描述
 * 功率集合 P 的最优元素
 *
 * 备注
 * 充电设备个数 n>0
 * 最优元素必须小于或等于充电站最大输出功率 p_max。
 *
 * 示例1
 * 输入:
 * 4
 * 50 20 20 60
 * 90
 * 输出:
 * 90
 * 说明:
 * 当充电设备输出功率50、20、20组合时，其输出功率总和为90，最接近充电站最大充电输出功率，因此最优元素为90.
 *
 * 示例2
 * 输入:
 * 2
 * 50 40
 * 30
 * 输出:
 * 0
 * 说明:
 * 所有充电设备的输出功率组合，均大于充电站最大充电输出功率30，此时最优元素值为0。
 *
 * 解题思路:
 * 用一个set来存放各种功率的组合，一开始set里面得有一个元素0，因为 当前功率P+0=P，用来方便遍历用的
 * 然后是两层for循环，第一层遍历数组的功率，中间还得临时加一个tempSet，为了防止一边遍历，一边前面set还会增加
 * 具体见下面的代码
 *
 */
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String numStr = sc.nextLine();
        int n = Integer.parseInt(numStr);

        String line2 = sc.nextLine();
        String[] split = line2.split(" ");

        String line = sc.nextLine();
        int pMax = Integer.parseInt(line);
        //使用此set来存放各种组合的输出功率总和
        Set<Integer> set = new HashSet<>();
        set.add(0);
        for (String str : split) {
            int curP = Integer.parseInt(str);
            Set<Integer> tempSet = new HashSet<>();
            for (int preAddP : set) {
                int newAddP = curP + preAddP;
                if (newAddP == pMax) {
                    System.out.println(pMax);
                    return;
                }
                if (newAddP < pMax) {
                    tempSet.add(newAddP);
                }
            }
            set.addAll(tempSet);
        }
        //因为一开始加了一个0进去了，如果只有一个元素，那么输出0
        if (set.size() == 1) {
            System.out.println(0);
            return;
        }
        //对set进行降序排列，取第一个
        List<Integer> list = new ArrayList<>(set);
        list.sort((a1, a2) -> a2 - a1);
        System.out.println(list.get(0));
    }
}
