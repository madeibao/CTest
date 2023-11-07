
import java.util.Deque;
import java.util.LinkedList;

public class Main {
    public static int[] maxSlidingWindow(int[] nums, int k) {
        Deque<Integer> deque = new LinkedList<>();
        int[] result = new int[nums.length - k + 1];

        for (int i = 0; i < nums.length; i++) {
            // 清理单调队列中过期的数据（超出窗口范围）
            if (!deque.isEmpty() && deque.getFirst() < i - k + 1) {
                deque.removeFirst();
            }
            // 在保证单调递减的情况下，放入窗口中出现的新数据
            while (!deque.isEmpty() && nums[deque.peekLast()] < nums[i]) {
                deque.pollLast();
            }
            deque.offerLast(i);

            // 获取结果，这里要注意的是：第一个窗口是出现在i=k-1
            if (i >= k - 1) {
                result[i - k + 1] = nums[deque.getFirst()];
            }
        }
        return result;
    }

    public static void main(String[] args) {

        int[] nums = {1,3,-1,-3,5,3,6,7};
        int k = 3;
        int[] res = maxSlidingWindow(nums,k);
        for(var i:res) {
            System.out.print(i+" ");
        }

    }
}
