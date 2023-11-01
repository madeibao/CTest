

/**
 * @ClassName StringAdd
 * @Author：Mayuan
 * @Date 2021/4/1/0001 9:17
 * @Description TODO
 * @Version 1.0
 *
 * 字符串相加，
 **/
public class StringAdd {

    static String add(String stra, String strb) {
        if(stra==null) {
            return strb;
        }
        if(strb==null) {
            return stra;
        }

        int lena = stra.length()-1;
        int lenb=  strb.length()-1;

        int carry = 0;
        StringBuilder sb= new StringBuilder();
        for(int i=lena,j=lenb;i>=0||j>=0;i--,j--) {
            char ca = stra!=null?stra.charAt(i):'0';
            char cb = strb!=null?strb.charAt(j):'0';

            int temp  = ca-'0'+cb-'0'+carry;
            sb.insert(0,temp%10);
            carry = temp/10;
        }
        sb.insert(0,carry>0?"1":"");
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println(add("12","34"));
    }
}
