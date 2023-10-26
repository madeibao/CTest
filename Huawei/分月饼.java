
public class DivideMooncake {
//非最优解，需要考虑减枝，减少遍历次数。
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int [] num = Arrays.stream(scanner.nextLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        //分配人数
        int peoples = num[0];
        //待分配数量
        int dnum = num[1] - num[0];
        //重新分配后每个人月饼数量
        int [] nums = new int[peoples];
        // 用一个List来存储所有分配方案
        List<List<Integer>> result = new ArrayList<>();
        divide(dnum,peoples,nums,result);
        List<List<Integer>>filteredResult = removeDuplicate(result);
        //System.out.println(filteredResult);
        System.out.println(filteredResult.size());
    }
 
    public static void divide(int num,int peolpe, int [] nums,List<List<Integer>> result){
        if (peolpe == 1){
            nums[0] = num;
            List<Integer> allocation = new ArrayList<>();
            for (int i : nums){
                allocation.add(i);
            }
            result.add(allocation);
            return;
        }
 
        for (int i = 0; i <= num ; i++){
            //要分配的月饼
            nums[peolpe - 1] = i;
            //递归调用，将要分配的月饼分配给其它人
            divide(num - i,peolpe -1,nums,result);
        }
 
    }
 
    /**
     * 判断是否满足条件  Max(n) - Max(n-1) >= 3
     * @param nums
     * @return
     */
    public static Boolean satisfy(List<Integer> nums){
        int i = nums.size() -1;
        while (i >= 1){
            if (nums.get(i) - nums.get(i - 1) > 3){
                return false;
            }
            i--;
        }
        return true;
    }

    /**
     * 分数一致的去重
     * @param result
     * @return
     */
    public static List<List<Integer>> removeDuplicate(List<List<Integer>> result) {
        List<List<Integer>> filteredResult = new ArrayList<>();
        for (List<Integer> allocation : result) {
            boolean duplicate = false;
            allocation.sort(Integer::compareTo); // 对分配方案进行排序
 
            for (List<Integer> existingAllocation : filteredResult) {
                existingAllocation.sort(Integer::compareTo); // 对已有的分配方案进行排序
 
                if (Arrays.equals(existingAllocation.toArray(), allocation.toArray())) {
                    duplicate = true; // 分配方案重复
                    break;
                }
            }
 
            if (!duplicate) {
                if (satisfy(allocation)){
                    filteredResult.add(allocation);
                }
            }
        }
 
        return filteredResult;
    }
 
}