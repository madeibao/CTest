


arr = list(map(int, input().split(",")))
# 2,10,-3,-8,40,5
# 4
k = int(input())
print(arr)
print(k)


def result():
    windowSum = 0
    for i in range(k):
        windowSum += arr[i]
    ans = windowSum
    for i, val in enumerate(arr[k:]):
        # i 为0,开始的，val是从arr[k]开始的。刚好对应。
        windowSum += val - arr[i]
        ans = max(ans,windowSum)
    return ans
print(result())