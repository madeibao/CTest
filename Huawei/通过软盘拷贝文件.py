

n = int(input())
arr = [int(input()) for i in range(n)]
print(arr)


import math
def result2():
    bagweight = 1474560//512 # 背包承重
    dp = [0] * (bagweight+1)
    for i in range(n):
        weight = math.ceil(arr[i-1]/512.0)
        value = arr[i-1]
        for j in range(bagweight,weight-1, -1):
            dp[j] = max(dp[j], dp[j-weight]+value)
    return dp[bagweight]
print(result2())