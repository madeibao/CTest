

import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Author: Amos
 * E-mail: amos@amoscloud.com
 * Date: 2022/4/24
 * Time: 15:22
 * Description:
 */
public class Main0089 {
  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      int m = scanner.nextInt();
      solution(m);
    }

  }

  private static void solution(int m) {

    if (m <= 1 || m >= 100) {
      System.out.println("ERROR");
      return;
    }

    List<Integer> list = new LinkedList<>();
    for (int i = 1; i <= 100; i++) {
      list.add(i);
    }
    int curNo = 0;
    int pos = 0;
    while (list.size() >= m) {
      curNo++;
      if (curNo == m) {
        list.remove(pos);
        curNo = 0;
      } else {
        pos++;
      }

      if (pos == list.size()) {
        pos = 0;
      }
    }

    for (int i = 0; i < list.size(); i++) {
      System.out.print(list.get(i));
      if (i != list.size() - 1) {
        System.out.print(',');
      }
    }
  }
}