

import java.util.*;


public class StringEncrypt {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int stringLine = Integer.parseInt(sc.nextLine());
        String[]encrypts = new String[stringLine];
        for (int i = 0; i < stringLine; i++){
            encrypts[i] = sc.next();
        }
        String[] end1 = encryptMe(encrypts);
        Arrays.stream(end1).forEach(System.out::println);
    }
 
    public static String[] encryptMe(String[]encrypts){
        String[] end = new String[encrypts.length];
        StringBuffer sb = new StringBuffer();
        for (int i = 0; i < encrypts.length; i++){
            char[] t1 = encrypts[i].toCharArray();
            for (int j = 0; j < t1.length;j++){
                //计算偏移量
                int offset1 = offset(j);
                //生成字符
                char value = (char) ((int)t1[j] + offset1);
                if (value > 122){
                     value = (char) ((int)t1[j] + offset1 - 26);
                }
                sb.append(value);
            }
            end[i] = sb.toString();
            sb.setLength(0);
        }
        return end;
    }
 
    /**
     * 偏移量计算
     * @param i
     * @return
     */
    public static int offset(int i){
       if (i == 0){
           return 1;
       } else if (i == 1) {
           return 2;
       } else if (i == 2) {
           return 4;
       }else {
           return offset(i-1) + offset(i-2) + offset(i - 3);
       }
    }
}