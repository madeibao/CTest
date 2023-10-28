# 输入获取
nums = list(map(int, input().split()))


# 算法入口
def getResult():
    n = len(nums)

    dp = [0] * n

    if n >= 1:
        dp[0] = nums[0]

    if n >= 2:
        dp[1] = max(nums[0], nums[1])

    for i in range(2, n):
        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i])

    return dp[n - 1]


# 算法调用
print(getResult())