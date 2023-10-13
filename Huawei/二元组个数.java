

public class My {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = Integer.parseInt(sc.nextLine());
        int n = Integer.parseInt(sc.nextLine());
        String[] stringsA = sc.nextLine().split(" ");
        String[] stringsB = sc.nextLine().split(" ");
        int[] aArray = Arrays.stream(stringsA).mapToInt(Integer::parseInt).toArray();
        int[] bArray = Arrays.stream(stringsB).mapToInt(Integer::parseInt).toArray();

        //map key是数值，value对应数值出现的次数
        Map<Integer, Integer> map = new HashMap<>();

        for (int key : aArray) {
            Integer num = map.getOrDefault(key, 0);
            num++;
            map.put(key, num);
        }

        int sum = 0;
        for (int key : bArray) {
            sum += map.getOrDefault(key, 0);
        }
        System.out.println(sum);
    }

}
