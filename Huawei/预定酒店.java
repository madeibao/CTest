


public class FindHotelA {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int [] value = Arrays.stream(sc.nextLine().split(" ")).mapToInt(Integer ::parseInt).toArray();
        int sum = value[0];
        int filterNum = value[1];
        int target = value[2];
        List<Integer> hotelValue = new ArrayList<>();
        for (int i = 0 ;i < sum ;i++){
            hotelValue.add(sc.nextInt());
        }
        // 根据酒店价格从低到高排序
        Collections.sort(hotelValue,(o1, o2) -> {
            int diff1 = Math.abs(o1- target);
            int diff2 = Math.abs(o2 -target);
            if (diff1 != diff2){
                return Integer.compare(diff1,diff2);
            }else {
                return Integer.compare(o1,o2);
            }
        });
        //取出差值最小的几个数，按酒店价格从低到高排列
        List<Integer> targetHotelValue = new ArrayList<>();
        for (int j = 0; j < filterNum; j++){
            targetHotelValue.add(hotelValue.get(j));
        }
        Collections.sort(targetHotelValue);
        targetHotelValue.forEach(item -> System.out.println(item));
    }
}