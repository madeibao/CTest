

public class C {

    public static String getString(String str) {

        int n = str.length();
        StringBuilder sb = new StringBuilder();
        int count = 0;
        int j = 0;
        int i = 0;
        for(;i<n;i=j) {
            char c = str.charAt(i);
            count = 0;
            j = i + 1;
            while(j<n) {
                if(str.charAt(j)==c) {
                    count++;
                }
                else {
                    break;
                }
                j++;
            }
            if(count==1) {
                sb.append(c);
                sb.append(c);
            }
            else if(count==0) {
                sb.append(str.charAt(j-1));
            }
            else if(count>=2) {
                sb.append(c);
                sb.append((count+1)+"");
            }
        }

        return sb.toString();
    }

    public static void main(String[] args) {
        String str2 = "aabbbbbcccccddaadbaaaa";
        String str = "aabbcddd";
        System.out.println(getString(str));
    }
}