


import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * Author: Amos
 * E-mail: amos@amoscloud.com
 * Date: 2021/3/3
 * Time: 14:38
 * Description:
 */
public class Main0024 {
  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      int n = Integer.parseInt(scanner.nextLine());
      String line = scanner.nextLine();
      solution(n, line);
    }
  }

  private static void solution(int n, String line) {
    String[] nums = line.split(" ");

    Set<Integer> ints = new TreeSet<>();
    for (String num : nums) {
      ints.add(Integer.parseInt(num));
    }

    if (ints.contains(1)) {
      System.out.println(1);
      return;
    }

    List<Integer> list = new ArrayList<>(ints);
    for (int i = 0; i < list.size(); i++) {
      Integer cur = list.get(i);
      for (int j = i + 1; j < list.size(); ) {
        if (list.get(j) % cur == 0) {
          list.remove(j);
        } else j++;
      }
    }
    System.out.println(list.size());
  }
}