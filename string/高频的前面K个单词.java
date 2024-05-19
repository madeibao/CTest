

public class Solution{ 
    
    public int[] topKFrequent(int[] nums, int k) {
    

        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i:nums) {
            map.put(i,map.getOrDefault(i,0)+1);
        }


        PriorityQueue<int[]> queue = new PriorityQueue<int[]>(new Comparator<int[]>() {

            @Override
            public int compare(int[] a, int[] b) {
                return b[1]-a[1];
            }
        });

        for(int key:map.keySet()) {
            queue.add(new int[]{key,map.get(key)});
        }

        int[] ans = new int[k];

        for(int i=0;i<k;i++) {
            ans[i] = queue.poll()[0];
        }

        return ans;
    }



}