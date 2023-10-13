



public class Solution {
    public String ReverseSentence(String str) {
        if (str == null || str.length() == 0) {
            return "";
        }
        String[] split = str.split(" ");
        Stack<String> stack = new Stack<>();
        for (int i = 0; i < split.length; i++) {
            stack.push(split[i]);
        }
        StringBuilder builder = new StringBuilder();
        while (!stack.isEmpty()) {
            builder.append(stack.pop()).append(" ");
        }
        return builder.toString().trim();
    }


    public static void main(String[] args) {
        String str = "nowcoder. a am I";
        String strs = str.split(" ");
        String res;
        Solution s2;
        res = s2.ReverseSentence(strs);
        System.out.println(res);
    }
}