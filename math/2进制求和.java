


public class Solution {
    public static String addBinary(String a, String b) {

        int carry = 0;
        int i = a.length()-1;
        int j = b.length()-1;
        StringBuilder sb = new StringBuilder();
        while(i>=0||j>=0||carry!=0) {

            int m = i>=0?a.charAt(i)-'0':0;
            int n = j>=0?b.charAt(j)-'0':0;

            int sum = m+n+carry;
            sb.insert(0,String.valueOf(sum%2));
            carry = sum/2;

            i--;
            j--;
        }

        if(carry>0) {
            sb.insert(0,"1");
        }

        return sb.toString();
    }

    public static void main(String[] args) {

        String a = "11", b = "10";
        System.out.println(addBinary(a,b));

    }
}

