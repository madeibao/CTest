


import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Author: Amos
 * E-mail: amos@amoscloud.com
 * Date: 2021/3/3
 * Time: 15:56
 * Description:
 */
public class Main0025 {

  public static final String COMMA = ",";

  public static void main(String[] args) {

    try (Scanner scanner = new Scanner(System.in)) {
      String line = scanner.nextLine();
      solution(line);
    }
  }

  private static void solution(String line) {
    String[] nums = line.split(COMMA);
    List<Integer> list = new ArrayList<>();
    for (String num : nums) {
      list.add(Integer.parseInt(num));
    }
    list.sort(new Comparator<Integer>() {
      @Override
      public int compare(Integer o1, Integer o2) {
        return getKey(o1) - getKey(o2);
      }

      public Integer getKey(int i) {
        i = i > 0 ? i : -i;
        return i % 10;
      }
    });

    for (int i = 0; i < list.size(); i++) {
      System.out.print(list.get(i));
      if (i != list.size() - 1) {
        System.out.print(COMMA);
      }
    }
  }
}


