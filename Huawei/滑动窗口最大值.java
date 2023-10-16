
import java.util.Deque;
import java.util.LinkedList;

/**
 * @Author
 * @Date 2023/5/3 20:45
 * abababb
 */
public class Main {
    public int[] maxSlidingWindow(int[] nums, int k) {


        int[] res = new int[nums.length - k + 1];
        Deque<Integer> queue = new LinkedList<>();

        for(int i=0;i<nums.length;i++) {
            if(!queue.isEmpty()&&queue.peekFirst()==i-k) {
                queue.pollFirst();
            }
            while(!queue.isEmpty() && nums[queue.peekLast()] < nums[i]){
                queue.pollLast();
            }
            queue.offerLast(i);
            if(i >= k - 1) {
                res[i + 1 - k] = nums[queue.peekFirst()];
            }
        }
        return res;
    }

    public static void main(String[] args) {
        int[] nums = {1,3,-1,-3,5,3,6,7};
        int k= 3;
        int[] res;
        res= new Main().maxSlidingWindow(nums,k);
        for(int i:res) {
            System.out.print(i+" ");
        }
    }
}