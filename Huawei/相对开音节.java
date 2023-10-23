


import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class T19 {
	public static void main(String[] args) {
		// new StringBuilder("cake a cafe cakekeke ekac").reverse().toString();
		String input = "!ekam a ekekac";
		String wordArr[] = input.split(" ");
		for (int i = 0; i < wordArr.length; i++) {
			String word = wordArr[i];
			// System.out.println(containNotCharacter(word));
			if (containNotCharacter(word) == false) {
				wordArr[i] = new StringBuilder(word).reverse().toString();
			}
		}
		int count = 0;
		for (String c : wordArr) {
			count += getRelativeNumber(c);
		}
		// 字符该反转的已反转
		// 相对开音节==》辅音+元音（aeiou）+辅音(r除外)+e
		// 辅音 除原因之外的字母
		System.out.println("结果：" + count);
	}

	public static int getRelativeNumber(String word) {
		StringBuilder tmpWord = new StringBuilder(word);
		Pattern pattern = Pattern
				.compile("[a-z&^aeiou]{1}[aeiou]{1}[a-z&^aeiour]{1}e");
		Matcher matcher = pattern.matcher(word);
		List<String> keySet = new ArrayList<>();
		while (matcher.find()) {
			// 可能是相对开音节的字符 还得看其出现的次数
			keySet.add(word.substring(matcher.start(), matcher.end()));
			word = word.replaceFirst(word.charAt(0) + "", "");
			matcher = pattern.matcher(word);
		}
		// 可能取到重复的
		Iterator<String> it = keySet.iterator();
		Set<Integer> indexSet = new HashSet<>();
		while (it.hasNext()) {
			String key = it.next();
			pattern = Pattern.compile(key);
			matcher = pattern.matcher(tmpWord.toString());
			while (matcher.find()) {
				indexSet.add(matcher.start());
				tmpWord.setCharAt(matcher.start(), '_');// 得一个就把开始索引换了
			}
		}
		return indexSet.size();
	}
	
	public static boolean containNotCharacter(String word) {
		Pattern pattern = Pattern.compile("[^a-z]+");
		Matcher matcher = pattern.matcher(word);
		return matcher.find();
	}
}
