
/**最大乘积
 * @author ASUS*/

/**
 * 拼接字符串
 */

public class Main {
    public static void main(String[] args) {
//        String input = ",/";
        String input = "/acm,/bb";
        String wordArr[] = input.split(",");

        if (wordArr.length == 0) {
            System.out.println("/");
            return;
        }

        if (wordArr.length == 1) {
            System.out.println("/" + wordArr[0]);
            return;
        }
        String prefix = wordArr[0];
        if (prefix.startsWith("/"))
            prefix = prefix.replaceFirst("/", "");
        String suffix = wordArr[1];
        if (suffix.startsWith("/"))
            suffix = suffix.replaceFirst("/", "");
        System.out.println("/" + prefix + "/" + suffix);
    }
}
