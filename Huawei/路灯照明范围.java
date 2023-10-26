

public class StreetLighting {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int lightNum = Integer.parseInt(sc.nextLine());
        List<Integer> radius = new ArrayList<>();
        for (int i = 0; i < lightNum; i++){
            radius.add(sc.nextInt());
        }
        int range = rang(radius);
        System.out.println(range);
    }
 
    public static int rang(List<Integer> radis){
        int range = 0;
        int left;
        int right = radis.get(0);
        int beforeRight = right;
        for (int i = 1; i < radis.size(); i++) {
            int value = 100 * (i);
            left = value - radis.get(i);
            right = value + radis.get(i);
            if (left > beforeRight) {
                range = range + (left - beforeRight);
            }
            beforeRight = right;
        }
        return range;
    }
}