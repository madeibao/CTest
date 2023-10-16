

public class ShareBonus {
    public static void main(String[] args) {
        String peopleNumber = "3";
        String peoperId = "2 10 3";
        int [] id = Arrays.stream(peoperId.split(" ")).mapToInt(Integer ::parseInt).toArray();
        List value = getValue(id);
        value.forEach(end -> System.out.println(end));
    }
 
    private static List<Integer> getValue(int[] id) {
        List<Integer> end = new ArrayList<>();
        Boolean b = true;
        for (int i = 0; i < id.length; i++){
            for (int j = i; j < id.length; j++){
                //有大于它的值
                if (id[j] > id[i]){
                    Integer money = (id[j] - id[i])*(j-i);
                    end.add(money);
                    b = false;
                    break;
                }
            }
            //后面没有大于它的值
            if (b) {
                end.add(id[i]);
            }
            b = true;
        }
        return end;
    }
 
}