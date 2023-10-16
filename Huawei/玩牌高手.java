


public class PlayCards {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> cards = Arrays.stream(sc.nextLine().split(",")).map(Integer::parseInt)
                .collect(Collectors.toList());
        int endScore = maxScore(cards);
        System.out.println(endScore);
    }
 
    public static int maxScore(List<Integer> cards){
        //若当前轮次小于等于3（即在第1、2、3轮选择跳过轮次），则总分数置为0。
        int max = 0;
        for (int i = 0; i < cards.size(); i++){
            //大于0的累计值
            if (cards.get(i) >= 0){
                max += cards.get(i);
            } else if (i > 2) {
                //当前值跟前三轮值比较，看是返回值，还是累计当前值
                max = Math.max(max + cards.get(i),cards.get(i-3));
            }else {
                max = Math.max(max + cards.get(i),0);
            }
        }
        return max;
    }
}

