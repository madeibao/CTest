



import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class RealPassWord {
	public static void main(String[] args) {
		String input="h he hel hell hello o ok n ni nin ninj ninja";
		List<String> wordList=new ArrayList<String>();
		String[] wordArr=input.split(" ");
		for(String w:wordArr){
			wordList.add(w);
		}
		wordList.sort(new Comparator<String>() {
			@Override
			public int compare(String o1, String o2) {
				//按长度降序排序
				if(o1.length()>o2.length())return -1;
				if(o1.length()<o2.length())return 1;
				//按字符排序
				for(int i=0;i<o1.length();i++){
					if(o1.charAt(i)>o2.charAt(i)) return -1;
					if(o1.charAt(i)<o2.charAt(i)) return 1;
				}
				return 0;
			}
		});
		
		System.out.println(wordList);
		for(String word:wordList){
			//双指针校验，是否全包含
			int left=0;
			int right=1;
			while(wordList.contains(word.substring(left, right))){
				if(right==word.length()){
					System.out.println(word);
					return;
				}
				right++;
			}
		}
	}
}

