

public class MessageDiscounts {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int money = Integer.parseInt(sc.nextLine());
        //性价比
        int[] messageCount = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer ::parseInt).toArray();
        ValueIndex [] valueIndices = new ValueIndex[messageCount.length + 1];
        HashMap<Integer,Integer> hashMap = new HashMap<>();
        //下标从1开始，表示价值
        for (int i = 1; i <= messageCount.length; i++){
            valueIndices[i] = new ValueIndex(i,(double)messageCount[i-1]/i);
            hashMap.put(i,messageCount[i-1]);
        }
        //截取下标从1开始的数组
        valueIndices = Arrays.copyOfRange(valueIndices,1,valueIndices.length);
        //按性价比排序
        Arrays.sort(valueIndices,Comparator.comparingDouble((ValueIndex o1) -> o1.value).reversed());
        //选出最合适的方案
        int allCount = 0;
        for (int j = 0; j < messageCount.length; j++){
            if (money == 0){
                break;
            }
            if (money >= valueIndices[j].index){
                money = money - valueIndices[j].index;
                allCount = allCount + hashMap.get(valueIndices[j].index);
            }
        }
        System.out.println(allCount);
    }
 
   static class  ValueIndex{
        int index;
        double value;
 
        public  ValueIndex(int index, double value) {
            this.index = index;
            this.value = value;
        }
   }
}