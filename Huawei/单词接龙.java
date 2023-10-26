

public class WordRelay {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int beginIndex = Integer.parseInt(sc.nextLine());
        int wordNums = Integer.parseInt(sc.nextLine());
        String [] word = new String[wordNums];
        List<Word> wordInfo = new LinkedList<>();
        for (int i = 0; i < wordNums; i++){
            word[i] = sc.next();
            if (i != beginIndex){
                wordInfo.add(new Word(word[i].length(),word[i]));
            }
        }
        find(word,beginIndex,wordInfo);
    }
 
 
    /**
     * 给List<Word>排序，初始化准备
     * @param word
     * @param beginIndex
     * @param wordInfo
     */
    public static void find(String[] word, int beginIndex , List<Word> wordInfo ){
        Collections.sort(wordInfo, (o1, o2) -> {
            if (o1.length != o2.length){
                return o2.length - o1.length;
            }else {
                return o1.word.compareTo(o2.word);
            }
        });
        //起始值
        String beginWord = word[beginIndex];
        String endSingleWord = beginWord.substring(beginWord.length()-1,beginWord.length());
        StringBuffer sb = new StringBuffer();
        sb.append(beginWord);
        appendWord(wordInfo, endSingleWord, sb,true);
    }
 
    /**
     * 从大到小的长度顺序拼接
     * @param wordInfo
     * @param endSingleWord
     * @param sb
     * @param end
     */
    private static void appendWord(List<Word> wordInfo, String endSingleWord, StringBuffer sb,Boolean end) {
        while (end){
            end = false;
            for (int i = 0; i < wordInfo.size(); i++){
                if (endSingleWord.equals(String.valueOf(wordInfo.get(i).word.charAt(0)))){
                    sb.append(wordInfo.get(i).word);
                    endSingleWord = wordInfo.get(i).word.substring(wordInfo.get(i).word.length()-1,wordInfo.get(i).word.length());
                    //添加完移除
                    wordInfo.remove(i);
                    end = true;
                    break;
                }
            }
        }
        System.out.println(sb.toString());
    }

    public static class Word{
        int length;
        String word;
 
        public Word(int length, String word) {
            this.length = length;
            this.word = word;
        }
    }
}