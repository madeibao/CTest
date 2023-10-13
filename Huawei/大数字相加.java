

public class Main {

    public static String solution(String s,String t){
        int slen = s.length()-1;
        int tlen = t.length()-1;
        int carry = 0;
        StringBuffer sb = new StringBuffer();
        while(slen>=0||tlen>=0||carry>0) {
            int snum = slen>=0?s.charAt(slen)-'0':0;
            int tnum = tlen>=0?t.charAt(tlen)-'0':0;
            int num = (snum+tnum+carry)%10;
            carry = (snum+tnum+carry)/10;
            sb.append(num);
            slen--;
            tlen--;
        }
        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        String str = "11";
        String strb= "22";
        System.out.println(solution(str,strb));
    }
}