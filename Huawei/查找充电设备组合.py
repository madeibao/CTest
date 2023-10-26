


n = int(input())
arr = list(map(int, input().split()))
pmax = int(input())
print(n, arr, pmax)

# 使用二维数组
weight = arr
value = arr
bagweight = pmax
dp =[[0]*(pmax+1) for j in range(len(weight))]
# 初始化 j表示背包嘛。j你至少要大于weight[0]啊
for j in range(weight[0], bagweight+1):
    dp[0][j]=value[0]
# 先遍历物品
for i in range(1, len(weight)):
    # 在遍历背包
    for j in range(bagweight+1):
        if j<weight[i]:
            dp[i][j] = dp[i-1][j] # 背包的重量小于weight[i],那么第i件物品只能不放啊
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]]+value[i])
print(dp[len(weight)-1][bagweight])




2
50 30
40
2 [50, 30] 40


#------------------------------------
30

