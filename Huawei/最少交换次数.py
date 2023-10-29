

# 输入获取
arr = list(map(int, input().split()))
k = int(input())
 
 
# 算法入口
def getResult():
    # 统计小于k的数组元素个数
    count = 0
    for num in arr:
        if num < k:
            count += 1
 
    # 如果只有1个小于k的元素，则不需要交换就能使小于k的元素组合在一起
    if count == 1:
        return 0
 
    # 先统计起点在0位置（即left=0）的滑动窗口的交换次数，得到一个minSwapCount初始值
    minSwapCount = 0
    for i in range(count):
        if arr[i] >= k:
            minSwapCount += 1
 
    # 然后统计起点（left）在1~arr.length-count位置的滑动窗口的交换次数
    # 可以转化为求解终点（right）在count~arr.length位置的滑动窗口的交换次数
    tmpSwapCount = minSwapCount
    for j in range(count, len(arr)):
        # 上一轮的left，即滑窗失去的元素的索引
        preLeft = j - count
        # j 为本轮滑窗新增的元素的索引
        if arr[preLeft] >= k > arr[j]:
            tmpSwapCount -= 1
        elif arr[preLeft] < k <= arr[j]:
            tmpSwapCount += 1
        minSwapCount = min(minSwapCount, tmpSwapCount)
 
    return minSwapCount
 
 
# 调用算法
print(getResult())


# 1 3 1 4 0
# 2