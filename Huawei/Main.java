
import java.util.Stack;

public class Main {

    public String reverseParentheses(String s) {
        Stack<Character> stack = new Stack<>();
        for(var c:s.toCharArray) {
            if(c==')') {
                StringBuilder sb = new StringBuilder();
                while(stack.peep()!='(') {
                    sb.append(stack.pop());
                }
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }

        StringBuilder result = new StringBuilder(); 
        while(!stack.empty()) {
            result.append(stack.pop());
        }

        return sb.reverse().toString();
    }

    public static void main(String[] args) {
        String s = "(u(love)i)";
        System.out.println(new Main().reverseParentheses(s));
    }
}