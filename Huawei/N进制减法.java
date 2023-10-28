import java.math.BigInteger;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Author: Amos
 * E-mail: amos@amoscloud.com
 * Date: 2021/4/30
 * Time: 17:20
 * Description:
 */
public class Main0049 {
  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      String line = scanner.nextLine();
      solution(line);
    }

  }

  private static void solution(String line) {
    try {
      String[] split = line.split(" ");
      int radix = Integer.parseInt(split[0]);
      if ((split[1].length() > 1 && split[1].startsWith("0")) ||
          split[2].length() > 1 && split[2].startsWith("0")) {
        System.out.print(-1);
        return;
      }

      BigInteger a = new BigInteger(split[1], radix);
      BigInteger b = new BigInteger(split[2], radix);

      BigInteger resBI = a.subtract(b);
      int signum = resBI.signum();
      String res = resBI.abs().toString(radix);

      System.out.println((signum == 1 ? "0" : "1") + " " + res);
    } catch (Exception e) {
      System.out.print(-1);
    }
  }
}