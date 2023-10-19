


a = [int(x) for x in input().split(',')]
m = int(input())
dp = [0] * (m + 1) # dp[n]表示恰好装成容量为n的方案数
dp[0] = 1 # 初始化dp[0] = 1,表示容量为0的方案为1种
for i in a:
    for j in range(m, i - 1, -1):
        dp[j] += dp[j - i] # 转移方程为：dp[n] += dp[n - i]
print(dp[m])