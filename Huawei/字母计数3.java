

import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.stream.Collectors;

/**
 * Created with IntelliJ IDEA.
 * Author: Amos
 * E-mail: amos@amoscloud.com
 * Date: 2021/9/7
 * Time: 15:30
 * Description:
 */
public class Main0070 {

  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      String line = scanner.nextLine();
      solution(line);
    }
  }

  private static void solution(String line) {

    char[] chars = line.toCharArray();
    Map<Character, Integer> map = new HashMap<>();
    
    for (char c : chars) {
      map.put(c, map.getOrDefault(c, 0) + 1);
    }

    List<Map.Entry<Character, Integer>> list = map.entrySet()
        .stream()
        .sorted((e1, e2) -> {
          char c1 = e1.getKey();
          char c2 = e2.getKey();
          int count1 = e1.getValue();
          int count2 = e2.getValue();
          if (count1 != count2) {
            return Integer.compare(count2, count1);
          }
          if ((c1 < 95 && c2 < 95) || (c1 > 95 && c2 > 95)) {
            return c1 - c2;
          } else {
            return c2 - c1;
          }
        })
        .collect(Collectors.toList());

    for (Map.Entry<Character, Integer> entry : list) {
      System.out.print(entry.getKey() + ":" + entry.getValue() + ";");
    }
  }
}