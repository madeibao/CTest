/**
 * A长宽度  B书长宽度 就可以叠放
 * 输出：最多可以叠放几本
 * 输入用例：
 //String book = "[[20,16],[10,10],[9,10],[15,11],[2,4],[8,9],[3,5],[8,10],[7,10]]";
 //String book = "[[20,20],[15,1],[10,5],[8,3]]";
 // String book = "[[20,20],[16,6],[15,4],[10,6],[8,3]]";
 // String book = "[[20,20],[15,1],[10,5],[8,3]]";
 //String book = "[[20,16],[10,10],[9,10],[15,11]]";
 //String book = "[[16,15], [13, 12], [15, 14]]";
 */
public class BookStacking {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String book = sc.nextLine();
        //匹配数字
        Pattern pattern = Pattern.compile("\\d+");
        //Pattern pattern = Pattern.compile("[a-zA-Z]+"); 匹配字母
        //Pattern pattern = Pattern.compile("\\D+"); 匹配非数字
        Matcher matcher = pattern.matcher(book);
        String [] size = book.split(",");
        int [][] value = new int[size.length/2][2];
        int i = 0;
        int j = 0;
        //将数字转化为List存储
        while(matcher.find()){
            String match = matcher.group();
            Integer integer = Integer.valueOf(match);
            value[i][j] = integer;
            if (matcher.find()){
                String match2 = matcher.group();
                Integer integer2 = Integer.valueOf(match2);
                j++;
                value[i][j] = integer2;
                j = 0;
            }
            i++;
        }
        //排序
        Arrays.sort(value,(Comparator.comparingInt(o -> o[0])));
        //动态规划，dp[i]表示第i本时，满足条件的最大数
        //思想类似连续递增子序列
        int[] dp = new int[value.length];
        dp[0] = 1;
        //比较书本长宽大小
        int count = 1;
        Arrays.fill(dp,1);
        for (int k = 1; k <= value.length - 1 ; k++){
            for (int m = 0; m < k ; m++){
                if (value[k][0] > value[m][0] && value[k][1] > value[m][1]){
                    dp[k] = Math.max(dp[k],dp[m]+1);
                }
                count = Math.max(count,dp[k]);
            }
        }
        System.out.println(count);
    }
}