


public class IslandSurvival {
    //5 10 8 -8 -5
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        List<Integer> power = Arrays.stream(sc.nextLine().split(" ")).map(Integer::parseInt).collect(Collectors.toList());
        List<Integer> right = new ArrayList<>();
        List<Integer> left = new ArrayList<>();
 
        //先将左右方向的人区分
        for (int i = 0; i < power.size(); i++) {
            if (power.get(i) > 0) {
                right.add(power.get(i));
            }
            else {
                left.add(power.get(i));
            }
        }
        int exit = fight(left,right);
        System.out.println(exit);
    }
 
    public static int fight(List<Integer> l,List<Integer> r){
        int exit = 0;
        //用个左右双指针
        int left = 0;
        int right = r.size() - 1;
 
        while (left < l.size() && right >= 0){
            //体力绝对值不相等,就会有一方能逃离
            //最最左边的跟左右边的人比
            if (Math.abs(l.get(left)) != Math.abs(r.get(right))){
                exit++;
            }
            left++;
            right--;
        }
        //左右方向的有剩余的没有参与战斗的人员
        exit +=  (l.size() -1)-(left - 1);
        exit +=  (right + 1);
        return exit;
    }
 
}