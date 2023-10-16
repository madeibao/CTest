

//----------------------------------------------------------------
// 评选出最差的产品内容



public class WorstProduct {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int range = Integer.parseInt(sc.nextLine());
        int [] score = Arrays.stream(sc.nextLine().split(",")).mapToInt(Integer ::parseInt).toArray();
        //滑动窗口
        int minScore = 0;
        for (int i = 0; i <= score.length - range; i++) {
            minScore = score[i];
            for (int j = i; j < i + range; j++) {
                minScore = Math.min(minScore, score[j]);
            }
            
            System.out.print(minScore);
            if (i != score.length - range) {
                System.out.print(",");
            }
        }
    }
}