


n = int(input())
res = [list(map(int,input().split())) for i in range(n)]
print(n)
# 3
# 15 8 7
# 12 20 9
# 11 7 5
print(res)


import sys
def minIdx(arr, preidx):
    # 先把值搞到最大。
    minVal = sys.maxsize
    minCur = -1
    # 逐个遍历，与上一个idx要进行比对，如果相等就跳过。
    for i in range(len(arr)):
        if i == preidx:
            continue
        # 不等就比较大小，求得最小值。
        if arr[i]<=minVal:
            minVal = arr[i]
            minCur = i
    return minCur


def result():
    last = -1
    total = 0
    for i in range(n):
        # 本次不能选上次选的，然后排序，选最小的。
        last = minIdx(res[i], last)
        total += res[i][last]
    return total
print(result())