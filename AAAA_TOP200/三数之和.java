package com.AAAA.www;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Main {

    public static List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> res = new ArrayList<>();

        int len = nums.length;
        if(nums==null||nums.length<3) {
            return res;
        }
        Arrays.sort(nums);
        for(int i=0;i<nums.length;i++) {
            if(nums[i]>0) {
                break;
            }

            if(i>0&&nums[i]==nums[i-1]) {
                continue;
            }

            // 最左和最右

            int L = i+1;
            int R = len-1;

            while (L<R) {
                int sum = nums[i] + nums[L] + nums[R];
                if(sum==0) {
                    res.add(Arrays.asList(nums[i],nums[L],nums[R]));
                    while (L<R) {
                        if(nums[L]==nums[L+1]) {
                            L++;
                        }
                    }
                    while (L<R) {
                        if(nums[R]==nums[R-1]) {
                            R--;
                        }
                    }
                    L++;
                    R--;
                }
                else if(sum<0) {
                    L++;
                }
                else if(sum>0) {
                    R--;
                }
            }
        }
        return res;

    }

    public static void main(String[] args) {
        int[] nums = {-1,0,1,2,-1,-4};
        List<List<Integer>> res;
        res = threeSum(nums);
        for(var i:res) {
            for(var j:i) {
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }
}
