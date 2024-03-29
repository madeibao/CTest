
样例
输入

6,3,1,6
3
输出

1
说明

无

输入

5,6,7,5,6,7
2
输出

0
说明

无

//-------------------------------------------------------------------------------------------------------

import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
 
public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
 
    int[] boxes = Arrays.stream(sc.nextLine().split(",")).mapToInt(Integer::parseInt).toArray();
    int len = Integer.parseInt(sc.nextLine());
 
    System.out.println(getResult(boxes, len));
  }
 
  public static int getResult(int[] boxes, int len) {
    // 统计该数字上一个箱子的编号
    HashMap<Integer, Integer> lastIdx = new HashMap<>();
    // 对应数字的箱子已经找到了，符合咒语要求的箱子对
    HashSet<Integer> find = new HashSet<>();
 
    int ans = -1;
 
    for (int i = 0; i < boxes.length; i++) {
      // 箱子上贴的数字
      int num = boxes[i];
 
      // 该数字是否已经找到符合咒语要求的箱子对，如果找到了，则不需要再看后面的，只找第一对即可
      if (find.contains(num)) continue;
 
      // 检查箱子对是否符合咒语要求
      if (lastIdx.containsKey(num) && i - lastIdx.get(num) <= len) {
        find.add(num);
        ans = ans == -1 ? lastIdx.get(num) : Math.min(ans, lastIdx.get(num));
      } else {
        lastIdx.put(num, i);
      }
    }
 
    return ans;
  }
}