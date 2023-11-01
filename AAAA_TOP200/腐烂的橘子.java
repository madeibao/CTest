class Solution {
    public int orangesRotting(int[][] grid) {
        Queue<int[]> queue= new LinkedList<>();

        int m = grid.length;
        int n = grid[0].length;

        int fresh = 0;
        int min = 0;

        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    fresh++;
                }
                else if(grid[i][j]==2) {
                    queue.offer(new int[]{i,j,0});
                }
            }
        }
        int[] dx = {0,0,-1,1};
        int[] dy = {-1,1,0,0};

        // 队列不为空的条件下
        while (!queue.isEmpty()) {
            int[] rot = queue.poll();

            int x = rot[0];
            int y = rot[1];

            min = rot[2];

            for(int i=0;i<4;i++) {
                int xa = x+dx[i];
                int ya = y+dy[i];

                if(xa>=0&&xa<m&&ya>=0&&ya<n&&grid[xa][ya]==1) {
                    grid[xa][ya]=2;
                    fresh--;
                    queue.offer(new int[]{xa,ya,min+1});
                }
            }
        }
        
        if(fresh>0) {
            return -1;
        }
        return min;
    }

    public static void main(String[] args) {
        int[][] nums = {{2,1,1},{1,1,0},{0,1,1}};
        cout<<s2.orangesRotting(nums)<<endl;

    }
}