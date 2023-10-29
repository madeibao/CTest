
arr=list(map(int, input().split()))
print(arr)

def result(arr):
    n = len(arr)
    # dp[i]表示：第i时刻可得正向分
    dp = [0]*n
    # delay表示第i时刻可得的负向分
    delay = [0]*n
    # socre总得分
    socre = [0] * n
    dp[0] = arr[0]
    socre[0] = arr[0]
    for i in range(n):
        dp[i] = min(100, dp[i-1]+arr[i]) #最多上报100条,
        delay[i] = delay[i-1] + dp[i-1]
        socre[i]=dp[i]-delay[i]
        # 达到 100 条时必须上报，此时完成首次上报，结束循环
        if dp[i]>=100:
            break
    print(max(socre))


result(arr)