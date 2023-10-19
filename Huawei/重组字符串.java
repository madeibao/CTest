
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main0092 {
  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      int count = Integer.parseInt(scanner.nextLine());
      String line = scanner.nextLine();
      solution(count, line);
    }
  }

  private static void solution(int count, String line) {
    String[] split = line.split("-");

    List<String> list = new ArrayList<>();
    StringBuilder builder = new StringBuilder();
    for (int i = 1; i < split.length; i++) {
      builder.append(split[i]);
    }
    String item = builder.toString();
    while (item.length() > 0) {
      if (item.length() >= count) {//截取
        list.add(item.substring(0, count));
        item = item.substring(count);
      } else {
        list.add(item);
        item = "";
      }
    }

    System.out.print(split[0] + "-");
    for (int i = 0; i < list.size(); i++) {
      System.out.print(convert(list.get(i)));
      if (i != list.size() - 1) {
        System.out.print('-');
      }
    }

  }

  private static String convert(String str) {
    int lower = 0;
    int upper = 0;
    for (int i = 0; i < str.length(); i++) {
      char ch = str.charAt(i);
      if (ch >= 'a' && ch <= 'z') {
        lower++;
      } else if (ch >= 'A' && ch <= 'Z') {
        upper++;
      }
    }
    if (lower > upper) {
      return str.toLowerCase();
    } else if (upper > lower) {
      return str.toUpperCase();
    } else {
      return str;
    }
  }
}