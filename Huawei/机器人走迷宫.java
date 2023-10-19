import java.util.HashSet;
import java.util.Objects;
import java.util.Scanner;
import java.util.Set;

/**
 * Created with IntelliJ IDEA.
 * Author: Amos
 * E-mail: amos@amoscloud.com
 * Date: 2022/5/16
 * Time: 10:02
 * Description:
 */
public class Main0121 {
  private static int xLen;
  private static int yLen;

  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      xLen = scanner.nextInt();
      yLen = scanner.nextInt();
      int n = scanner.nextInt();

      int[][] walls = new int[n][2];
      for (int i = 0; i < n; i++) {
        walls[i][0] = scanner.nextInt();
        walls[i][1] = scanner.nextInt();
      }

      solution(walls);
    }
  }

  static class Check {
    int x;
    int y;

    public Check(int x, int y) {
      this.x = x;
      this.y = y;
    }

    @Override
    public boolean equals(Object o) {
      if (this == o) return true;
      if (o == null || getClass() != o.getClass()) return false;
      Check check = (Check) o;
      return x == check.x && y == check.y;
    }

    @Override
    public int hashCode() {
      return Objects.hash(x, y);
    }

  }

  private static void solution(int[][] walls) {
    int trapCount = 0;
    int invalidCount = 0;
    Set<Check> wallSet = new HashSet<>();
    for (int[] wall : walls) {
      wallSet.add(new Check(wall[0], wall[1]));
    }
    Set<Check> checks = new HashSet<>();
    Set<Check> finish = new HashSet<>();

    //  x, y
    findOut(0, 0, wallSet, checks, finish);

//    System.out.println(checks);
    invalidCount = xLen * yLen - checks.size() - wallSet.size();
//    System.out.println(finish);

    // trapTest
    for (Check check : finish) {
      Set<Check> checksT = new HashSet<>();
      Set<Check> finishT = new HashSet<>();
      findOut(check.x, check.y, wallSet, checksT, finishT);
      if (!finishT.contains(new Check(xLen - 1, yLen - 1))) {
        trapCount++;
      }
    }
    System.out.print(trapCount + " " + invalidCount);
  }

  private static void findOut(int x, int y, Set<Check> wallSet, Set<Check> checks, Set<Check> finish) {

    if (x == xLen - 1 && y == yLen - 1) {
      finish.add(new Check(x, y));
    }

    if (x >= xLen || y >= yLen) {
      return;
    }

    checks.add(new Check(x, y));
    // 北
    if (!wallSet.contains(new Check(x, y + 1))) {
      findOut(x, y + 1, wallSet, checks, finish);
    } else {
      finish.add(new Check(x, y));
    }
    // 东
    if (!wallSet.contains(new Check(x + 1, y))) {
      findOut(x + 1, y, wallSet, checks, finish);
    } else {
      finish.add(new Check(x, y));
    }
  }
}