


import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class T21 {
	public static void main(String[] args) {
		String input1 = "ace";
		String input2 = "abeceee";
		String regex = ""; // a[a-z]*c[a-z]*e[a-z]*
		for (int i = 0; i < input1.length(); i++) {
			regex += input1.charAt(i) + "[a-z]*";
		}
		System.out.println(regex);
		Pattern pattern = Pattern.compile(regex);
		Matcher matcher = pattern.matcher(input2);
		// public int end() 返回最后匹配字符之后的偏移量。
		if (matcher.find()) {
			System.out.println(matcher.end() - 1);
		}else{
			System.out.println(-1);
		}
	}
}



