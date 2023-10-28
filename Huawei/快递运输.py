

# 输入获取
arr = list(map(int, input().split(",")))
bagweight = int(input())

# 算法入口
def getResult():
    n = len(arr)
    dp = [0]*(bagweight+1)
    for i in range(n):
        weight = arr[i]
        values = 1
        for j in range(bagweight, weight-1, -1):
            dp[j] = max(dp[j], dp[j-weight] + values)
    return dp[bagweight]
# 调用算法
print(getResult())