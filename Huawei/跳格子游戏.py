



def rob(nums, start, end):
    pre2, pre1 = 0, 0
    for i in range(start, end + 1):
        cur = max(pre1, pre2 + nums[i])
        pre2 = pre1
        pre1 = cur
    return pre1


if __name__=="__main__":
    nums = list(map(int, input().split()))
    if len(nums) == 1:
        print(nums[0])
    else:
        print(max(rob(nums, 0, len(nums) - 2), rob(nums, 1, len(nums) - 1)))