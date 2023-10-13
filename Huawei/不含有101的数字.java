


public class Main{

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNext()) {
            int left = in.nextInt();
            int right = in.nextInt();

            int count = 0;
            for (int i = left; i <= right; i++) {
                String str = Integer.toBinaryString(i);
                if (str.contains("101")) {
                    continue;
                }
                count++;
            }
            System.out.println(count);
        }
    }
}
