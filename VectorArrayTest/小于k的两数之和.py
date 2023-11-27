





class Solution(object):
    def twoSumLessThanK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """

        nums.sort()

        left = 0
        right = len(nums) - 1
        res = -1
        while left < right:
            if nums[left] + nums[right] < k:
                res = max(res, nums[left] + nums[right])
                left += 1
            else:
                right -= 1
        
        return res


if __name__ == '__main__':
    nums = [34,23,1,24,75,33,54,8]
    K = 60
    s  = Solution()
    print(s.twoSumLessThanK(nums, K))