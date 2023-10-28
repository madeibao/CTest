


n = int(input())
arr = list(map(int, input().split()))
print(n)
print(arr)


def result(arr):
    # highBit 是一个数组，由于题目说给定的 A[i]取值小于 2^30，
    # 因此我们可以定义一个 30长度的数组，其元素含义是，比如 highBit[i]代表最高位 1 处于第 i 位的数的个数
    # highBit = [0] * 30
    highBit = [0] * 60 # 经网友反馈这里长度改为 60 可得 100%通过率
    for a in arr:
        binStr = format(a, 'b') # 转化为二进制。
        print("binStr", binStr)
        length = len(binStr) # 数的二进制形式字符串（无前导 0）的长度，就是该数二进制最高位 1 所处位数
        # 将一位二进制数“0”和“1”区别开来
        if binStr == "0":
            highBit[0] += 1
        else:
            highBit[length] += 1
    # 排除统计个数为 0 的情况
    highBit = list(filter(lambda d:d>0, highBit))
    # 最高位相同不能算，所以相同的
    print("highBit:", highBit)
    # highBit: [2, 2] 相当于2*2种
    # [2, 2, 1] 相当于2*2 + 2*1 +2*1两两组合嘛。
    ans = 0
    for i in range(len(highBit)):
        for j in range(i+1, len(highBit)):
            ans += highBit[i] * highBit[j]
    return ans
# arr = [4, 3, 5, 2, 8]
print(result(arr))