

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * <br>Author: Amos
 * <br>E-mail: amos@amoscloud.com
 * <br>Date: 2023/1/3
 * <br>Time: 9:03
 * <br>Description:
 */
public class Main0182 {
  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      int n = scanner.nextInt();
      scanner.nextLine();
      String[] jobs = new String[n];
      for (int i = 0; i < n; i++) {
        jobs[i] = scanner.nextLine();
      }
      solution(jobs);
    }
  }

  private static void solution(String[] jobs) {
    HashMap<String, List<int[]>> printers = new HashMap<>();
    for (int i = 0; i < jobs.length; i++) {
      String[] split = jobs[i].split(" ");
      String op = split[0];
      String num = split[1];
      if (op.equals("IN")) {
        int p = Integer.parseInt(split[2]);
        in(printers, num, i + 1, p);
      } else {
        String res = out(printers, num);
        System.out.println(res);
      }
    }
  }

  private static String out(HashMap<String, List<int[]>> printers, String num) {
    String res = "NULL";
    if (!printers.containsKey(num)) {
      return res;
    }
    List<int[]> jobList = printers.get(num);
    if (jobList.size() == 0) {
      return res;
    }
    jobList.sort((o1, o2) -> o2[1] - o1[1]);
    int seq = jobList.get(0)[0];
    jobList.remove(0);
    return seq + "";
  }

  private static void in(HashMap<String, List<int[]>> printers, String num, int seq, int p) {
    if (!printers.containsKey(num)) {
      printers.put(num, new ArrayList<>());
    }
    List<int[]> jobList = printers.get(num);
    jobList.add(new int[]{seq, p});
  }
}