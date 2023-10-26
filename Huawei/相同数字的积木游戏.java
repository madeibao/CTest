

import java.util.*;


/**
 * 相同数字的积木游戏1
 * 知识点数组循环map
 * 时间限制：1s 空间限制：256MB 限制语言：不限
 *
 * 题目描述：
 * 小华和小薇一起通过玩积木游戏学习数学。
 * 他们有很多积木，每个积木块上都有一个数字，积木块上的数字可能相同。
 * 小华随机拿一些积木挨着排成一排，请小薇找到这排积木中数字相同且所处位置最远
 * 的2块积木块，计算他们的距离。
 * 小薇请你帮忙替解决这个问题。
 *
 * 输入描述：
 * 第一行输入为N，表示小华排成一排的积木总数。
 * 接下来N行每行一个数字，表示小华排成一排的积木上数宇·
 *
 * 输出描述：
 * 相同数宇的积木的位置最远距离；
 * 如果所有积木数字都不相同，请返回-1．
 *
 * 补充说明：
 * 0<=积木上的数字<10^9
 * 1<=积木长度<=10^5
 *
 * 示例1：
 * 输入：
 * 5
 * 1
 * 2
 * 3
 * 1
 * 4
 * 输出：
 * 3
 *
 * 示例2：
 *输入：
 * 2
 * 1
 * 2
 * 输出：
 * -1
 *
 * 解题思路：
 * 可以利用map来做这个题目，keys是数值，value是下标
 * 如果map里有，就计算距离并比较
 * 没有，就存放
 */
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String numStr = sc.nextLine();
        int n = Integer.parseInt(numStr);
        //用map存放，key是数值，value是下标
        Map<Integer, Integer> map = new HashMap<>();
        int maxDistance = -1;

        for (int i = 0; i < n; i++) {
            int num = Integer.parseInt(sc.nextLine());
            //如果map里有，就计算距离并比较
            if (map.containsKey(num)) {
                int distance = i - map.get(num);
                maxDistance = Math.max(distance, maxDistance);
            }else {
                //没有，就存放
                map.put(num, i);
            }
        }
        System.out.println(maxDistance);

    }
}
