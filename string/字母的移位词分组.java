

class Solution {
    public static List<List<String>> groupAnagrams(String[] strs) {
        //哈希表，排好序的单词 -> 该单词对应的单词集合
        Map<String, List<String>> groups = new HashMap<>();

        for (String str : strs) {
            char[] charArray = str.toCharArray();

            //计算每个单词映射的排好序的单词
            Arrays.sort(charArray);
            String newStr = new String(charArray);

            groups.putIfAbsent(newStr, new LinkedList<>());
            groups.get(newStr).add(str);
        }
        return new LinkedList<>(groups.values());
    }

    public static void main(String[] args) {

        String[] strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
        List<List<String>> list2 = new ArrayList<>();

        list2 = groupAnagrams(strs);
        for (var i : list2) {
            for (var j : i) {
                System.out.print(j + " ");
            }
            System.out.println();
        }
    }
}
