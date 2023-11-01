
import java.util.LinkedList;

public class Main {
    public String decodeString(String s) {
        StringBuilder ans = new StringBuilder();
        int multi = 0;

        LinkedList<Integer> countStack = new LinkedList<>();
        LinkedList<String> strStack = new LinkedList<>();

        for(char c:s.toCharArray()) {

            if(c>='0'&&c<='9') {
                multi =multi*10+Integer.parseInt(c+"");
            }

            else if(c=='[') {
                countStack.addLast(multi);
                strStack.addLast(ans.toString());

                multi = 0;
                ans = new StringBuilder();
            }

            else if(c==']') {
                StringBuilder temp = new StringBuilder();
                int count = countStack.removeLast();
                for(int i=0;i<count;i++) {
                    temp.append(ans);
                }
                ans = new StringBuilder(strStack.removeLast()+temp);
            }

            else {
                ans.append(c);
            }
        }

        return ans.toString();
    }

    public static void main(String[] args) {
        String s = "3[a]2[bc]";
        System.out.println(new Main().decodeString(s));
    }
}
