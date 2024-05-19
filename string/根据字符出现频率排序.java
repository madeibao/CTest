

class Solution {
    public String frequencySort(String s) {
        HashMap<Character,Integer> map = new HashMap();
        // for(char j:s.toCharArray()) {
        //     map.put(j,map.getOrDefault(j,0)+1);
        // }

        for(char j:s.toCharArray()) {
            map.put(j,map.getOrDefault(j,0)+1);
        }

        List<Character> list = new ArrayList<Character>(map.keySet());

        Collections.sort(list,(a,b)->map.get(b)-map.get(a));

        StringBuilder sb = new StringBuilder();

        int size = list.size();

        for(int i=0;i<size;i++) {
            char c = list.get(i);
            int fre = map.get(c);

            for(int t=0;t<fre;t++) {
                sb.append(c);
            }
        }
        
        return sb.toString();
    }
}


//--------------------------------------------------------------------------------------------------------------------

class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i ++ ) {
            char c = s.charAt(i);
            map.put(c, map.getOrDefault(c, 0) + 1);
        }

        // 优先权队列
        PriorityQueue<Character> heap = new PriorityQueue<>((a, b) -> map.get(b) - map.get(a));
        for (char c : map.keySet()) heap.offer(c);
        StringBuffer sb = new StringBuffer();
        while (!heap.isEmpty()) {
            char c = heap.poll();
            int fre = map.get(c);
            while (fre -- > 0) {
                sb.append(c);
            }
        }
        return sb.toString();
    }
}