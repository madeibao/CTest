

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

public class 字母组合 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        Map<String, String> map = new HashMap<>();
        map.put("0", "abc");
        map.put("1", "def");
        map.put("2", "ghi");
        map.put("3", "jkl");
        map.put("4", "mno");
        map.put("5", "pqr");
        map.put("6", "st");
        map.put("7", "uv");
        map.put("8", "wx");
        map.put("9", "yz");
        while (in.hasNext()) {
            String str = in.next();
            String gxStr = in.next();
            
            String[] strings = str.split("");
            List<String> path = new ArrayList<>();
            dfs(map, strings, 0, new StringBuilder(), path);
            StringBuilder stringBuilder = new StringBuilder();
            for (String pa : path) {
                if (!pa.contains(gxStr)) {
                  stringBuilder.append(pa).append(" ");
                }
            }

            System.out.println(stringBuilder.toString().trim());

        }
    }

    public static void dfs(Map<String, String> map, String[] strings, int startIndex, StringBuilder sb, List<String> path) {
        if (startIndex == strings.length) {
            path.add(sb.toString());
            return;
        }
        String mapValues = map.get(strings[startIndex]);
        for (int i = 0; i < mapValues.length(); i++) {
            sb.append(mapValues.charAt(i));
            dfs(map, strings, startIndex + 1, sb, path);
            sb.deleteCharAt(sb.length() - 1);
        }
    }

}

