


# #这种背包问题是有价值的问题

# 有 n 个物品和一个大小为 m 的背包. 给定数组 A 表示每个物品的大小和数组 V 表示每个物品的价值.

# 问最多能装入背包的总价值是多大?
# 样例 :

#     输入: m = 10, A = [2, 3, 5, 7], V = [1, 5, 2, 4]
#     输出: 9
#     解释: 装入 A[1] 和 A[3] 可以得到最大价值, V[1] + V[3] = 9

# 思路同上：

#     数组中存放的是当前的最大价值
# ————————————————
# 版权声明：本文为CSDN博主「cy_dream」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
# 原文链接：https://blog.csdn.net/qq_33304418/article/details/101306184



def backpack1(m, A, V): 
    n = len(A)
    if n <= 0 or m <= 0:
        return 0
    dp = [0] * (m+1)
    for i in range(n):
        for j in range(m, A[i]-1, -1):
            dp[j] = max(dp[j-A[i]] + V[i], dp[j])
    return dp[-1]
 

 
def backpack2(m, A, V):
    n = len(A)
    if n <= 0 or m <= 0:
        return 0
    # 行 m+1, 列 len(A)
    dp = [[0]*(m + 1) for _ in range(n)]
    # 初始化 首行
    for i in range(m+1):
        if A[0] <= i:
            dp[0][i] = V[0]
 
    for i in range(1, n):
        for j in range(1, m+1):
            if A[i] > j: # 当前价值大于总价值, 则取i-1之前的最大价值
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j-A[i]] + V[i], dp[i-1][j])
    return dp[-1][-1]
 
if __name__ == '__main__':
    m = 10
    A = [2, 3, 5, 7]
    V = [1, 5, 2, 4]
    print('一维dp ', backpack1(m, A, V))
    print('二维dp ', backpack2(m, A, V))