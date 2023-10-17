

import java.util.ArrayList;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class T25 {
	public static void main(String[] args) {
		String input="My sisiter is in the house not in the yard";
		String[] words=input.split(" ");
		List<String> wordList=new ArrayList<String>();
		for(String word:words){
			//单词内部 对每个单词重新按字典排序
			char[] chArr=word.toCharArray();
			List<Character> characters=new ArrayList<>();
			for(char ch:chArr){
				characters.add(ch);
			}
			characters.sort(new Comparator<Character>() {
				@Override
				public int compare(Character o1, Character o2) {
					if(o1>o2){
						return 1;
					}else if(o1<o2){
						return -1;
					}
					return o1;
				}
			});
			StringBuilder sb=new StringBuilder();
			for(Character c:characters){
				sb.append(c);
			}
			wordList.add(sb.toString());
		}
		//遍历wordList 确定出现的次数
		final Map<String, Integer> wordCountMap=new HashMap<String, Integer>();
		for(String word:wordList){
			if(wordCountMap.containsKey(word)){
				wordCountMap.put(word, wordCountMap.get(word)+1);
			}else{
				wordCountMap.put(word, 1);
			}
		}
		wordList.sort(new Comparator<String>() {
			@Override
			public int compare(String w1, String w2) {
				//1)统计每个单词出现的次数，并按次数 降序排列Q
				//2) 次数相同，按 单词长度升序排列
				//3)次数和单词长度均相同，按字典升序排列
				if(wordCountMap.get(w1)>wordCountMap.get(w2)){
					return -1;
				}else if(wordCountMap.get(w1)<wordCountMap.get(w2)){
					return 1;
				}
				//次数相同的 按 单词长度升序排列
				if(w1.length()>w2.length()){
					return 1;
				}else if(w1.length()<w2.length()){
					return -1;
				}
				//次数和单词长度均相同，按字典升序排列
				int wordLen=w1.length();
				for(int i=0;i<wordLen;i++){
					if(w1.charAt(i)==w2.charAt(i)){
						continue;
					}
					if(w1.charAt(i)>w2.charAt(i)){
						return 1;
					}else{
						return -1;
					}
				}
				return 0;
			}
		});
		for(String s:wordList){
			System.out.print(s+" ");
		}
	}
}
