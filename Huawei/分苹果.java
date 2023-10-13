


/**
 常用的位运算符：
 与（&） 同1出1，有0出0
 或（|）有1出1，全0出0
 异或（^）相同出0，不同出1
 非（~）又叫取反
 左移 <<  （即乘2，最右边加个0）
 右移 >>  （即除2删掉最右边一位）
 */
public class ShareApple {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = Integer.parseInt(sc.nextLine());
        int[] apple = new int[num];
        for (int i = 0; i < num ;i++){
            apple[i] = sc.nextInt();
        }
        int x = 0;
        for (int j = 0; j < apple.length;j++){
            //把所有苹果重量累加异或，如果结果为0则满足A条件，那么B在所有苹果中最小的一个给A，其它归B
            x ^= apple[j];
        }
        //能满足A条件评分
        if (x==0){
            Arrays.sort(apple);
            int bApple = 0;
            for (int i = 1;i <apple.length;i++){
                bApple +=apple[i];
            }
            System.out.println(bApple);
            //不能满足A条件分苹果
        }else if (x!=0){
            System.out.println(-1);
        }
    }
}