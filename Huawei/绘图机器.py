

n, e = map(int, input().split())
tmp = [list(map(int, input().split())) for i in range(n)]
'''
4 10
1 1
2 1
3 1
4 -2
'''
print(n, e)
print(tmp)


offsets = [0]*e
for x, offsetY in tmp:
    offsets[x] = offsetY
def result():
    if e == 0:
        return 0
    dp = [0]*e
    ans = dp[0] = offsets[0]
    for i in range(1, e):
        # 转移方程。
        dp[i] = dp[i-1] + offsets[i]
        ans += abs(dp[i])
    return ans
print(result())