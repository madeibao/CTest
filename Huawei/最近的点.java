import java.util.Scanner;


/**
 * Created with IntelliJ IDEA.
 * Author: Amos
 * E-mail: amos@amoscloud.com
 * Date: 2021/3/13
 * Time: 14:01
 * Description:
 */
public class Main0033 {
  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      int n = scanner.nextInt();
      int m = scanner.nextInt();
      int r = scanner.nextInt();
      int[] collA = new int[n];
      int[] collB = new int[m];
      for (int i = 0; i < n; i++) {
        collA[i] = scanner.nextInt();
      }
      for (int i = 0; i < m; i++) {
        collB[i] = scanner.nextInt();
      }
      solution(r, collA, collB);
    }
  }

  private static void solution(int r, int[] collA, int[] collB) {
    for (int Ai : collA) {
      for (int Bj : collB) {
        if (Ai <= Bj && Bj - Ai <= r) {
          System.out.println(Ai + " " + Bj);
          break;
        }
      }
    }
  }
}