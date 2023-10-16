
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

/**
 * @Author
 * @Date 2023/5/6 23:47
 */
public class 树上逃离 {

    public static List<List<Integer>> result = new ArrayList<>();
    public static List<Integer> res = new ArrayList<>();

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int n = in.nextInt();
            int edge = in.nextInt();
            Map<Integer, List<Integer>> listMap = new HashMap<>();
            for (int i = 0; i < edge; i++) {
                int x = in.nextInt();
                int y = in.nextInt();
                if (listMap.containsKey(x)) {
                    listMap.get(x).add(y);
                } else {
                    List<Integer> list = new ArrayList<>();
                    list.add(y);
                    listMap.put(x, list);
                }
            }

            int block = in.nextInt();
            Set<Integer> set = new HashSet<>();
            for (int i = 0; i < block; i++) {
                set.add(in.nextInt());
            }

            res.clear();
            result.clear();
            List<Integer> path = new ArrayList<>();
            path.add(0);
            dfs(listMap, set, 0, path);
            System.out.println(result);
            System.out.println(res);

            if (result.isEmpty()) {
                System.out.println("NULL");
            } else {
                for (int i = 0; i < res.size(); i++) {
                    System.out.print(res.get(i));
                    if (i != res.size() - 1) {
                        System.out.print("->");
                    }
                }
                System.out.println();
            }


        }
    }

    public static void dfs(Map<Integer, List<Integer>> listMap, Set<Integer> set, int root, List<Integer> path) {
        if (set.contains(root)) {
            return;
        }
        // 当该节点没有连接节点时则为叶子节点
        if (!listMap.containsKey(root)) {
            result.add(new ArrayList<>(path));
            if (!res.isEmpty() && res.size() > path.size()) {
                res.clear();
                res.addAll(new ArrayList<>(path));
                return;
            }
            if (res.isEmpty()) {
                res.addAll(new ArrayList<>(path));
            }
            return;
        }
        List<Integer> list = listMap.get(root);
        for (int i = 0; i < list.size(); i++) {
            path.add(list.get(i));
            dfs(listMap, set, list.get(i), path);
            path.remove(path.size() - 1);
        }
    }
}

