

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
            String[] str = sc.nextLine().split(",");

            List<String> list2 = new ArrayList<>();
            for(var i:str) {
                list2.add(i);
            }
            
            // Lambda表达式计算
            list2.sort((o1, o2) -> (o2 + o1).compareTo(o1 + o2));

            StringBuilder sb = new StringBuilder();
            for(int i=0;i<list2.size();i++) {
                sb.append(list2.get(i));
            }
            System.out.println(sb.toString());
        }
    }
}
