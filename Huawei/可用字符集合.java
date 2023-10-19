


import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * Author: Amos
 * E-mail: amos@amoscloud.com
 * Date: 2021/5/26
 * Time: 19:38
 * Description:
 */
public class Main0060 {
  public static class Item {

    public String c;
    public int num;
    public int count;

    public Item(String c, int num, int count) {
      this.c = c;
      this.num = num;
      this.count = count;
    }
  }

  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      String line = scanner.nextLine();
      solution(line);
    }
  }

  private static void solution(String line) {
    String[] split = line.split("@");

    HashMap<String, Item> map = new HashMap<>();

    String[] all = split[0].split(",");
    for (int i = 0; i < all.length; i++) {
      String[] char_count = all[i].split(":");
      String c = char_count[0];
      int count = Integer.parseInt(char_count[1]);
      map.put(c, new Item(c, i, count));
    }


    if (split.length > 1)
      for (String s : split[1].split(",")) {
        String[] char_count = s.split(":");
        String c = char_count[0];
        Item item = map.get(c);
        item.count -= Integer.parseInt(char_count[1]);
        map.put(c, item);
      }

    StringBuilder sb = new StringBuilder();

    map.values().stream().filter(x -> x.count > 0)
        .sorted(Comparator.comparingInt(o -> o.num)).forEach(x ->
        sb.append(x.c)
            .append(":")
            .append(x.count)
            .append(","));

        System.out.println(sb.substring(0, sb.length() - 1));
    }


}