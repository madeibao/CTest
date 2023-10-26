
-1
-1 0 1 1 1 0 1 0 1 -1 1
1




public class GoBang {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int chessPieces = Integer.parseInt(sc.nextLine());
        List<Integer> chessBoard = Arrays.stream(sc.nextLine().split(" "))
                .map(Integer::parseInt).collect(Collectors.toList());
        insertPosition(chessPieces,chessBoard);
 
    }
    public static void insertPosition(int chessPieces, List<Integer> chessBoard){
        //找到空位
        List<Integer> blank = new LinkedList<>();
        for (int i = 0; i < chessBoard.size();i++){
            if (chessBoard.get(i) == 0){
                blank.add(i);
            }
        }
        //向前、向后遍历连续值（最大连续（靠近中间坐标），长度不超过5）
        index(blank,chessBoard,chessPieces);
    }
 
    public static void index(List<Integer> blank, List<Integer> chessBoard ,int chessPieces){
        int middle = chessBoard.size()/2;
        ChessInfo chess1 = new ChessInfo(-1,-1);
        for (int i = 0; i < blank.size(); i++){
            //空白位置插入棋子的连续个数
            int letf = blank.get(i) - 1;
            int right = blank.get(i) + 1;
            int count = 1;
            Boolean end = true;
            while (end && letf >= 0 && right <= chessBoard.size() -1){
                //向前位置遍历
                if (chessBoard.get(letf) == chessPieces){
                    letf--;
                    count++;
                    continue;
                }else if (chessBoard.get(right) == chessPieces){//向后遍历
                    right++;
                    count++;
                    continue;
                }
                end = false;
            }
            //保留最合适的位置 比较连续值，比较离中间位置最近
            if (chess1.count < count && count <= 5){
                chess1.count = count;
                chess1.index = blank.get(i);
            } else if (chess1.count == count && count <= 5) {
                if (Math.abs(chess1.index - middle) > Math.abs(blank.get(i) - middle)){
                    chess1.index = blank.get(i);
                }
            }
        }
        System.out.println(chess1.index);
    }

    @Data
    static class ChessInfo{
        int count;
        int index;
 
        public ChessInfo(int count, int index) {
            this.count = count;
            this.index = index;
        }
    }
}