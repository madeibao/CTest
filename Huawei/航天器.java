


import java.util.Arrays;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Author: Amos
 * E-mail: amos@amoscloud.com
 * Date: 2020/11/30
 * Time: 11:44
 * Description:
 */
public class Main0013 {
  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      String line = scanner.nextLine();

      solution(line);
    }

  }

  private static void solution(String line) {
    String[] split = line.split(",");
    long[] longs = Arrays.stream(split)
        .mapToLong(Long::parseLong)
        .toArray();

    long res = 0;
    for (int i = 0; i < split.length; i++) {
      for (int j = i + 1; j < split.length; j++) {
        long area = Math.min(longs[i], longs[j]) * (j - i);
        res = Math.max(res, area);
      }
    }

    System.out.println(res);
  }
}