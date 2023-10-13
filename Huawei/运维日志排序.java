

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.Map;
import java.util.TreeMap;


public class Main {
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int num = Integer.parseInt(br.readLine());
        String[] str = new String[num];
        for (int i = 0 ; i < str.length ; i++) {
            str[i] = br.readLine();
        }
        //构造一个可以升序排列的treemap
        Map<String, String> map = new TreeMap<>(new Comparator<String>() {
            public int compare(String o1, String o2) {
                return o1.compareTo(o2);
            }
        });
        //把比较的存在key，把真实要输出的存在value
        for (int i = 0 ; i < str.length ; i++) {
            String[] s = str[i].replace(".", ":").split(":");
            String res = "";
            if (s[0].length() == 1) {
                res += "0" + s[0];
            } else {
                res += s[0];
            }
            if (s[1].length() == 1) {
                res += "0" + s[1];
            } else {
                res += s[1];
            }
            if (s[2].length() == 1) {
                res += "0" + s[2];
            } else {
                res += s[2];
            }
            if (s[3].length() == 1) {
                res += "00" + s[3];
            } else if (s[3].length() == 2) {
                res += "0" + s[3];
            } else {
                res += s[3];
            }
            //相同时间，则按照顺序加入到map
            if (map.containsKey(res)) {
                map.put(res + 1, str[i]);
            } else {
                map.put(res, str[i]);
            }
        }
        //按照key来get，就输出value
        for (String ss : map.keySet()) {
            System.out.println(map.get(ss));
        }
    }
}
