
n = int(input())
# 4
# 3 2 6 3
# 0 1 1 0
# 2

goods = list(map(int, input().split()))
types = list(map(int, input().split()))
k = int(input())
print(n,k)
print(goods)
print(types)


def help(arr,cap,k):
    if cap<min(arr):
        # cap 比最小的还小，cap设置小了0表示小了，1表示大了。
        return 0
    ans = 0 # 需要车的数量。
    sumV = 0 # 当前车的载重。
    for g in arr:
        if sumV + g > cap:
            ans += 1 # 需要一辆新车
            sumV = g # 把货物放到新车上。
        else:
            sumV += g
    # return 1 if ans <=k else 0
    return ans<=k

def result(n,goods, types,k):
    # 有干货，有湿货
    gan = []
    shi = []
    for i in range(n):
        if types[i] == 0:
            gan.append(goods[i])
        else:
            shi.append(goods[i])
    # 题目说了一个供货商的货只能装到一辆车上不能拆装，也就是说限重最小是max(goods),最大值就是把所有的货物装到一辆车上。
    l, r = max(goods), sum(goods) # 这里要想清楚。
    while l<r:
        m = (l+r)//2
        mid = help(gan,m,k) and help(shi,m,k)
        print(mid)
        # 0 1 模型，取到第一个1
        if mid:
            r = m # 说明取大了
        else:
            l = m+1
    return l
result(n,goods, types,k)


