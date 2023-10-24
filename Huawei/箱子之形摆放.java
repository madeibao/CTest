//  解题思路：
//  本题不难，主要的技巧点在于处理奇数列和偶数列的时候，正序和倒序的问题，这个要画图才能理解



public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.nextLine();
        String[] strings = line.split(" ");
        int n = Integer.parseInt(strings[1]);
        //map key用来存放每一行的下标,value对应的字符串
        Map<Integer, String> map = new HashMap<>();
        String letterStr = strings[0];
        for (int i = 0; i < letterStr.length(); i++) {
            int columnIdx = i/n;
            //如果是偶数列，那么是正序，奇数列是倒序
            int index;
            if (columnIdx % 2 == 0) {
                //索引正序
                index = i % n;
            }else {
                //如果是奇数列，那么是倒序
                index = n - 1 - i % n;
            }
            String str = map.getOrDefault(index, "");
            String val = str + letterStr.charAt(i);
            map.put(index, val);

        }
        for (int key : map.keySet()) {
            System.out.println(map.get(key));
        }


    }

}
