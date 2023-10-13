



public class GoldChest {
    public static void main(String[] args) {
        Scanner sc =  new Scanner(System.in);
        int [] num = Arrays.stream(sc.nextLine().split(",")).mapToInt(Integer::parseInt).toArray();
        if (num.length == 1){
            System.out.println(0);
            return;
        }
        int end = equal(num,1);
        System.out.println(end);
    }
 
    //单指针+循环遍历
    public static int equal(int [] num, int i){
        Boolean end = false;
        while (!end && i < num.length) {
            int before = 0;
            int after = 0;
            for (int j = 0; j < num.length; j++) {
                if (j < i) {
                    before += num[j];
                } else if (j > i) {
                    after += num[j];
                }
            }
            if (before == after) {
                end = true;
            } else {
                i++;
            }
        }
        if (!end) {
            return -1;
        }
        return i;
    }
}