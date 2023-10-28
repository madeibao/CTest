

arr =list(map(int, input().split()))
print(arr)


import sys
def result(arr):
    minDiff = sys.maxsize
    ans = None
    # 要注意，0拉倒128的话是要加上128的，255拉倒128是要加上-127的所以才有了range(-127, 129)
    for k in range(-127, 129):
        sum = 0
        for j in range(len(arr)):
            # 先算arr[j] + k,如果小于0，那么取0，所以max(0, arr[j]+k), 
            # 如果大于255，就要取255。所以是min(max(0, arr[j]+k), 255)
            newVal = min(max(0, arr[j]+k), 255)
            sum += newVal
        diff = abs(sum/len(arr) - 128)
        # 开始与minDiff比对。
        if diff <minDiff:
            minDiff = diff
            ans = k
        elif diff == minDiff and ans is not None:
            # 如有多个整数 k 都满足，输出小的那个 k
            ans = min(ans, k)
    return ans
print(result(arr))