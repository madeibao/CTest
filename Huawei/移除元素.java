
/**
 * @ClassName Main
 * @Author：Mayuan
 * @Date 2021/4/11/0011 20:56
 * @Description TODO
 * @Version 1.0
 * <p>
 * 在一些考试中，类的命名常常为 Main
 **/

public class Main {
    public int removeElement(int[] nums, int val) {
        int left = 0;
        int right = nums.length;
        while (left < right) {
            if (nums[left] == val) {
                nums[left] = nums[right - 1];
                right--;
            } 
            else {
                left++;
            }
        }
        return left;
    }

    public static void main(String[] args) {
        int[]  nums = {3,2,2,3};
        int val = 3;
        System.out.println(new Main().removeElement(nums,val));
    }

}