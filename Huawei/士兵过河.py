


n = int(input())
t = int(input())
times = list(map(int, input().split()))


# 算法
def getmax(t1, t2):
    # 传进来的条件就是t1 < t2
    if t1*10 < t2:
        return t1 * 10
    else:
        return t2

def result(n, t, times):
    times.sort() # 上来排序下。
    # 初始化dp
    dp = [0] * n
    dp[0] = times[0]
    if dp[0]>t: # 如果时间太短，最快的都过不了就没法过了。
        return "0 0"
    dp[1] = getmax(times[0], times[1]) # 厉害。
    for i in range(2, n): # 只要是两个的都要调用下getmax
        dp[i] = min(dp[i-1]+ times[0] + getmax(times[0],times[i]), dp[i-2] + times[0] + getmax(times[i-1], times[i]) + times[1] + getmax(times[0], times[1]))
        if dp[i] > t:
            return f"{i} {dp[i-1]}" # 注意下标
    return f"{n} {dp[n-1]}"



print(result(n,t,times))

'''
7
171
25 12 13 15 20 35 20

'''