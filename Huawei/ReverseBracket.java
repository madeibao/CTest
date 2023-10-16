
import java.util.Stack;

public class ReverseBracket {

    public String reverseParentheses(String s) {
        Stack<Character> stack = new Stack<>();
        for(var c:s.toCharArray()) {
            if(c==')') {
                StringBuilder sb = new StringBuilder();
                while(stack.peek()!='(') {
                    sb.append(stack.pop());
                }
                stack.pop();

                for(var ch:sb.toString().toCharArray()) {
                    stack.push(ch);
                }
            }
            else {
                stack.push(c);
            }
        }

        StringBuilder result = new StringBuilder(); 
        while(!stack.empty()) {
            result.append(stack.pop());
        }
        return result.reverse().toString();
    }

    public static void main(String[] args) {
        String s = "(u(love)i)";
        System.out.println(new Main().reverseParentheses(s));
    }
}