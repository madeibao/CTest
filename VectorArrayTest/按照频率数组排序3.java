 
 
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
 
public class Main {
    public int[] frequencySort(int[] nums) {
        Map<Integer, Integer> cnt = new HashMap<Integer, Integer>();
        for (int num : nums) {
            cnt.put(num, cnt.getOrDefault(num, 0) + 1);
        }
        List<Integer> list = new ArrayList<Integer>();
        for (int num : nums) {
            list.add(num);
        }

        Collections.sort(list, (a, b) -> {
            int cnt1 = cnt.get(a);
            int cnt2 = cnt.get(b);
            return cnt1 != cnt2 ? cnt1 - cnt2 : b - a;
        });

        int length = nums.length;
        for (int i = 0; i < length; i++) {
            nums[i] = list.get(i);
        }
        
        return nums;
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


