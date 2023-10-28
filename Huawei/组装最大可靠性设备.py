

class Device:
    def __init__(self,rel,price) -> None:
        self.rel = rel
        self.price = price

# 搜集器件的可靠性。
reliabilities = set()
# 各个种类。
kinds = [[] for i in range(n)]
# arr的格式[type,reliability, price]
for ty, rel, price in arr:
    kinds[ty].append(Device(rel, price))
    reliabilities.add(rel)

def bs(kind, target):
    l = 0
    r = len(kind) - 1
    while l <= r: # 左闭右闭
        m = (l+r)//2
        mid = kind[m]
        if mid.rel > target:
            r = m - 1
        elif mid.rel < target:
            l = m + 1
        else:
            return m
    # 啥都搞不定了。
    return -l-1 # 这里有技巧的哈。

def check(rel):
    # 先记录和
    sumPrice = 0
    for kind in kinds:
        # kind内的器件已经按照可靠性升序排列了。
        # 我们只要找kind种类中国找到一个可靠性>=maxreliability的器件。
        idx = bs(kind, rel)
        # 如果idx<0,返回的是插入的位置
        if idx < 0:
            idx = -idx - 1
        # 如果idx = len(kind) 就相当于kind内所有的可靠性都低于maxreliability
        # 因此kind器件选取不到，只能返回false
        if idx == len(kind):
            return False
        # 否则，选取对应的idx位置的器件，并计入到价格总价里。
        sumPrice += kind[idx].price
        # 返回总价是否小于等于s
    return sumPrice <= s
        

def result():
    # 排序一波
    for kind in kinds:
        # 每一类，按照器件的可靠性排序。
        kind.sort(key=lambda x:x.rel)
    # 将所有器件的可靠性集合，变为数组
    ans = -1
    maybe = list(reliabilities)
    maybe.sort() # 升序排列
    # 二分法，选取可能最大的maybe
    l = 0
    r = len(maybe)-1
    while l <= r:
        m = (l + r) // 2
        # 如果可靠性
        if  check(maybe[m]):
            # 如果maybe[m]可以保证所有种类器件都能选到，且价格之和小于s
            ans = maybe[m]
            # maybe[m]相当于可能的解，相当于0-1模型的1，但是我要找到第一个1
            # 尝试更优解，找更大的可靠性
            l = m + 1
        else:
            # 这个就说明可靠性选高了，就要继续尝试更低的可靠性。
            r = m - 1 # 因为是左闭右闭，所以要m-1
    return ans


s, n = map(int, input().split())
total = int(input()) # 多少商品
arr = [list(map(int, input().split())) for i in range(total)]

print(result())