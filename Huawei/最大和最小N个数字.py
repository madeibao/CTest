
# m = int(input())
# arr = list(map(int, input().split()))
# n = int(input())
# print(arr)
# print(m, n)



matrix = [95, 88, 83, 64, 100]
m, n = 5, 2
def result():
    # 先对数组去重
    arr = list(set(matrix))
    # 不能有交叉
    if len(arr) < n*2:
        return -1
    arr.sort()
    if arr[0]< 0 or arr[-1] >1000:
        return -1
    # 求最大N个数与最小N个数的和
    return sum(arr[:n]) + sum(arr[-n:])
print(result())