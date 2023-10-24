

import java.util.*;

public class Main {
    public int[] frequencySort(int[] nums) {
        Map<Integer,Integer> map = new HashMap<>();
        for(int num:nums){
            map.put(num,map.getOrDefault(num,0)+1);
        }
        List<Map.Entry<Integer,Integer>> list = new ArrayList<>(map.entrySet());

        Collections.sort(list,(o1, o2)->{
            if(o1.getValue()==o2.getValue()) {
                return o2.getKey() - o1.getKey();
            }
            return o1.getValue()-o2.getValue();
        });

        int[] res = new int[nums.length];
		
        int index = 0;
        for(Map.Entry<Integer,Integer> m:list){
            for(int i = 0; i < m.getValue();++i){
                res[index++] = m.getKey();
            }
        }
        return res;
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