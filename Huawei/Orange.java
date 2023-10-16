
import java.util.LinkedList;
import java.util.Queue;

/**
 * @Author
 * @Date 2023/5/3 20:45
 * abababb
 */
public class Orange {
    public int orangesRotting(int[][] grid) {
        Queue<int[]> queue = new LinkedList<>();
        int m = grid.length, n = grid[0].length;
        int fresh = 0, min = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 2) {
                    queue.offer(new int[]{i, j, 0});
                } 
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int[] dx = {1, 0, 0, -1};
        int[] dy = {0, 1, -1, 0};
        while(!queue.isEmpty()) {
            int[] rot = queue.poll();
            int x = rot[0], 
            int y = rot[1];
            min = rot[2];
            for(int i = 0; i < 4; i++) {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if(x1 >= 0 && x1 < m && y1 >= 0 && y1 < n && grid[x1][y1] == 1) {
                    grid[x1][y1] = 2;
                    fresh--;
                    queue.offer(new int[]{x1, y1, min + 1});
                }
            }
        }
        if(fresh != 0) {
            return -1;
        }
        return min;
    }
    public static void main(String[] args) {
        int[][] nums = {{2,1,1},{1,1,0},{0,1,1}};
        System.out.println(new Orange().orangesRotting(nums));
    }
}