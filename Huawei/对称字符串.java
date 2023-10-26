
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        for (int i = 0; i < n; i++) {
            int k = in.nextInt();
            long j = in.nextLong();
            System.out.println(dfs(k, j));
        }

    }


    private static String dfs(int k, long j) {
        if (k == 1) {
            return "red";
        }
        

        long n = 1L << (k - 2);

        if (j >= n) {
            return dfs(k - 1, j - n);
        } else {
            if ("blue".equals(dfs(k - 1, j))) {
                return "red";
            } else {
                return "blue";
            }
        }
    }

}
