

public class Main {

    static String longest(String str) {
        int len = str.length();
        if(len<2) {
            return str;
        }

        int maxLen = 1;
        String res = str.substring(0,1);
        for(int i=0;i<len-1;i++) {
            String stra = getString(str,i,i);
            String strb = getString(str,i,i+1);

            String strC = stra.length()>strb.length()?stra:strb;
            if(strC.length()>maxLen) {
                res = strC;
                maxLen = strC.length();
            }
        }
        return res;
    }

    static String getString(String str, int i, int j) {

        while(i>=0&&j<str.length()) {
            if(str.charAt(i)==str.charAt(j)) {
                i--;
                j++;
            }
            else {
                break;
            }
        }
        return str.substring(i+1,j);
    }

    public static void main(String[] args) {
        String str = "babad";
        System.out.println(longest(str));
    }
}
