
# 就是01背包问题，那我就处理成这个样子啦
bagweight, n=map(int, input().split())
weight = []
value = []
for i in range(n):
    w, v = map(int, input().split())
    weight.append(w)
    value.append(v)

dp = [0] * (bagweight+1)
# 先遍历物品
for i in range(len(weight)):
    # 在遍历背包
    for j in range(bagweight, weight[i]-1, -1):
        dp[j] = max(dp[j], dp[j-weight[i]]+value[i])
print(dp[bagweight])


# dp = [[0]*(bagweight+1) for j in range(len(weight))]
# # 初始化dp[0][j]
# for j in range(weight[0], bagweight+1):
#     dp[0][j] = value[0]
# #先遍历物品 
# for i in range(1,len(weight)):
#     # 在遍历背包
#     for j in range(bagweight+1):
#         if j<weight[i]:
#             dp[i][j] = dp[i-1][j]
#         else:
#             dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i])
# print(dp[len(weight)-1][bagweight])