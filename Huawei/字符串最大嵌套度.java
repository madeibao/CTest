


import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Stack;

/**
 * Created with IntelliJ IDEA.
 * Author: Amos
 * E-mail: amos@amoscloud.com
 * Date: 2022/8/8
 * Time: 17:03
 * Description:
 */
public class Main0105 {
  public static void main(String[] args) {
    try (Scanner scanner = new Scanner(System.in)) {
      String line = scanner.nextLine();
      solution(line);
    }
  }

  private static void solution(String line) {

    char[] chars = line.toCharArray();
    int maxDepth = 0;
    Stack<Character> stack = new Stack<>();
    Map<Character, Character> map = new HashMap<>();
    map.put(')', '(');
    map.put(']', '[');
    map.put('}', '{');

    for (char cur : chars) {
      if (cur == '(' || cur == '[' || cur == '{') {
        stack.push(cur);
        maxDepth = Math.max(maxDepth, stack.size());
        continue;
      }

      if (cur == ')' || cur == ']' || cur == '}') {
        if (stack.size() == 0) {
          System.out.print(0);
          return;
        }
        Character left = stack.lastElement();
        Character c = map.get(cur);
        if (left.equals(c)) {
          stack.pop();
        } else {
          System.out.print(0);
          return;
        }
      }

    }

    if (stack.size() == 0) {
      System.out.print(maxDepth);
    } 
    else {
      System.out.print(0);
    }
  }
}