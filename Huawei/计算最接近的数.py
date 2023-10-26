

# 输入获取
tmp = input()
 
i = tmp.rfind(",")
 
x = list(map(int, tmp[1:i-1].split(",")))
k = int(tmp[i+1:])
 
 
# 核心代码
def result():
    n = len(x)
 
    # x数组的中位数
    mid = sorted(x)[n // 2]
 
    # 初始化滑窗0~k-1, window为滑窗内部元素的表达式计算结果
    window = x[0]
    for j in range(1, k):
        window -= x[j]
 
    # window和中位数的差距
    minDiff = abs(mid - window)
    # window滑窗起始索引
    idx = 0
 
    # 滑窗右移
    for i in range(1, n-k+1):
        # 右移一格后，新滑窗的表达式计算结果
        window += -x[i-1] + 2 * x[i] - x[i + k -1]
 
        # 新滑窗window值和中位数的差距
        diff = abs(mid - window)
 
        # 结果最接近于数组中位数的下标 i ，如果有多个 i 满足条件，请返回最大的 i
        if diff <= minDiff:
            minDiff = diff
            idx = i
 
    return idx
 
 
# 算法调用
print(result())