
import java.util.*;

public class QuanPaiLie {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String str = in.nextLine();
        in.close();
        char[] ch = str.toCharArray();
        Arrays.sort(ch);  // 排序是剪枝的前提
        Deque<Character> path = new ArrayDeque<>(); // 用栈构造path，存储已经选择的字符
        boolean[] used = new boolean[ch.length];  // 判断字符是否使用过
        List<List<Character>> res = new ArrayList<>();
        dfs(ch, 0, path, used, res);
        System.out.println(res.size());
    }
    private static void dfs(char[] ch, int depth, Deque<Character> path, boolean[] used, List<List<Character>> res) {
        if (depth == ch.length) {  // 当遍历的层数等于数组长度时结束
            res.add(new ArrayList<>(path));
            return ;
        }
        for (int i = 0; i < ch.length; i++) {
            if (used[i]) {
                continue;
            }
            // 剪枝
            if (i > 0 && ch[i] == ch[i - 1] && !used[i - 1]) {
                continue;
            }
            path.addLast(ch[i]);
            used[i] = true;
            dfs(ch, depth + 1, path, used, res);
            path.removeLast();
            used[i] = false;
        }
    }
}
