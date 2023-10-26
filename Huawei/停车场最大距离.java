import java.util.Scanner;

// 1,0,0,0,0,1,0,0,1,0,1
// 2


/**
 * Created with IntelliJ IDEA.
 * Author: Amos
 * E-mail: amos@amoscloud.com
 * Date: 2021/5/7
 * Time: 19:57
 * Description: 90%
 */
public class Main0051 {
  public static void main(String[] args) {

    try (Scanner scanner = new Scanner(System.in)) {
      String line = scanner.nextLine();
      solution(line);
    }

  }

  private static void solution(String line) {
    String siteStr = line.replaceAll(",", "");
    char[] sites = siteStr.toCharArray();

    int max = 0;

    for (int i = 0; i < sites.length; i++) {
      char cur_site = sites[i];
      if (cur_site == '0') {
        int pre = siteStr.indexOf('1', i);
        int suf = siteStr.lastIndexOf('1', i);
        if (pre == -1) pre = 100;
        if (suf == -1) suf = siteStr.length() - 1;
        int min = Math.min(pre - i, i - suf);
        if (min > max) max = min;
      }
    }

    System.out.println(max);
  }
}