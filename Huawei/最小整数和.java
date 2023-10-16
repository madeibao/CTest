


public class MinInteger {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String words = sc.nextLine();
        int minInteger = find(words);
        System.out.println(minInteger);
    }
 
    public static int find(String words){
        int min = 0;
        //负数值
        Boolean negative = false;
        StringBuffer sb = new StringBuffer();
        //判断是否是整数,最小整数：每个正整数 + 最大负整数
        for (int i = 0; i < words.length();i++){
            if (Character.isDigit(words.charAt(i))){
                //累计正整数值或负数值
                if (!negative){
                    min+= Character.getNumericValue(words.charAt(i));
                } else if (negative) {
                    sb.append(words.charAt(i));
                }
            } else if (String.valueOf(words.charAt(i)).equals("-")) {//判断是否开启负数值累计
                negative = true;
            } else if (negative){
                negative = false;//结束，累加负数值
                min-= Integer.valueOf(sb.toString());
                sb.setLength(0);
            }
        }
        //字符串尾数是负数值
        if (negative){
            min-= Integer.valueOf(sb.toString());
        }
        return min;
    }
}