


n = int(input())
weights = list(map(int,input().split()))
print(weights)


def result(n, weights):
    weights.sort() # 先来排序一把
    minV = weights[0] # 初始化。
    correctSum = minV
    faultSum = minV
    for i in range(1, n):
        correctSum += weights[i]
        faultSum ^= weights[i]
    # 算完之后就开始判断了
    if faultSum == 0:
        return str(correctSum-minV)
    else:
        return "NO"
print(result(n, weights))
