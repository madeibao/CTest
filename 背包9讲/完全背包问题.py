

# 完全背包算法是假设物品可以无限制的使用。

def backpack(m, A, V):
    n = len(A)
    if n <= 0 or m <= 0:
        return 0
    # 行 m+1, 列 len(A)
    dp = [[0]*(m + 1) for _ in range(n)]
    # 初始化首行, i(当前背包容量0 ~ m+1) / A[0](重量) * V[0](价值)
    for i in range(m+1):
        dp[0][i] = i // A[0] * V[0]
 
    for i in range(1, n):
        for j in range(1, m+1):
            for k in range(j):
                if k*A[i] <= j:
                    dp[i][j] = max(dp[i-1][j-k*A[i]]+k*V[i], dp[i-1][j], dp[i][j])
                else:
                	break
    return dp[-1][-1]

# ----------------------------------------------------------------
# 一维度的动态规划算法。


def backpack(m, A, V): 
    n = len(A)
    if n <= 0 or m <= 0:
        return 0
    dp = [0] * (m+1)
    # i: 0 ~ n
    for i in range(n):
        # j: A[i] ~ m+1 重复使用
        for j in range(A[i], m+1):
            dp[j] = max(dp[j-A[i]] + V[i], dp[j])
    return dp[-1]
 
if __name__ == '__main__':
    m = 10
    A = [2, 3, 5, 7]
    V = [1, 5, 2, 4]
    # 15
    print(backpack(m, A, V))

    
 
if __name__ == '__main__':
    m = 10
    A = [2, 3, 5, 7]
    V = [1, 5, 2, 4]
    # 15
    print(backpack1(m, A, V))