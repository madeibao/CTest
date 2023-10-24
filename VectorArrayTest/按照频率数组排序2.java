 
 
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
 
public class Main {
    public int[] frequencySort(int[] nums) {
        HashMap<Integer, Integer> val2cnt = new HashMap<>();
        for (int x : nums) {
            val2cnt.merge(x, 1, Integer::sum);
        }
 
        return Arrays.stream(nums)
                .boxed()
                .sorted(Comparator.<Integer>comparingInt(val2cnt::get)
                        .thenComparing(Comparator.reverseOrder()))
                .mapToInt(Integer::intValue)
                .toArray();
    }
 
    public static void main(String[] args) {
        int[] nums = {3,2,2,2,1,1,};
        int[] res;
        res = new Main().frequencySort(nums);
        for(var i:res) {
            System.out.print(i+" ");
        }
    }
}






class Solution {
    public int[] frequencySort(int[] nums) {

        Map<Integer, Integer> help = new HashMap<>();

        // 统计每个数值的频率
        Arrays.stream(nums).forEach(n -> help.put(n, help.getOrDefault(n, 0) + 1));

        // 自定义 sort
        return Arrays.stream(nums).boxed()
                .sorted((a,b) -> !help.get(a).equals(help.get(b)) ? help.get(a) - help.get(b) : b - a)
                .mapToInt(n -> n)
                .toArray();

    }
}
