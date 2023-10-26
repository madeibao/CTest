
public class CanteenCatering {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int times = Integer.parseInt(sc.nextLine());
        int lunchs = Integer.parseInt(sc.nextLine());
        int[]peoples = new int[times];
        int sum = 0;
        for (int i = 0; i < times; i++){
            peoples[i] = sc.nextInt();
            sum+= peoples[i];
        }
        //最小做餐数量
        int m = (int) Math.ceil((double) (sum - lunchs)/ times);
        m = work(peoples,m,lunchs);
        System.out.println(m);
    }
 
    public static int work(int [] peoples,int m,int lunchs){
        boolean end = false;
        int beginLunchs = lunchs;
        while (!end){
            end = true;
            //验证是否满足条件
            for (int i = 0; i < peoples.length; i++){
                //先判断剩余盒饭数
                if (lunchs  < peoples[i]){
                    end = false;
                    break;
                }
                //够的情况下 + 单位时间做的
                lunchs = lunchs + m - peoples[i];
            }
            if (!end){
                //最小做餐数+1
                m++;
                //初始化盒饭数
                lunchs = beginLunchs;
            }
        }
       return m;
    }
}