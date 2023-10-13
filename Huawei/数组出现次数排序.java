

去重排序
描述
给定一个乱序的数组，删除所有的重复元素，使得每个元素只出现一次，并且按
照出现的次数从高到低进行排序，
相同出现次数按照第一次出现顺序进行先后排序。

1 3 3 3 2 4 4 4 5
3 4 1 2 5


public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String[] str = in.nextLine().split(" ");
        int[] ints = new int[str.length];
        for (int i = 0; i < ints.length; i++) {
            ints[i] = Integer.parseInt(str[i]);
        }
        LinkedHashMap<Integer, Integer> map = new LinkedHashMap<>();
        for (int i = 0; i < ints.length; i++) {
            /** 统计数字出现的频次*/
            map.put(ints[i], map.getOrDefault(ints[i], 0) + 1);
        }

        
        /**Map按value排序，先将map转为list,再排序list*/
        LinkedList<Map.Entry<Integer,Integer>> list = new LinkedList<>(map.entrySet());
        list.sort((o1,o2) -> o2.getValue() - o1.getValue());
        for(int i = 0 ; i < list.size() ;i++){
            Map.Entry<Integer , Integer> entry = list.get(i);
            if(i != list.size()-1){
                System.out.print(entry.getKey() + " ");
            }else{
                System.out.print(entry.getKey() );
            }
        }
    }
}
