

def partition(link, index, buckets, subSum):
    if index == len(link): return True
    select = link[index]
    for i in range(len(buckets)):
        if i>0 and buckets[i] == buckets[i-1]:
            continue
        if select+buckets[i] <= subSum:
            buckets[i]+=select
            if partition(link, index+1,buckets, subSum):
                return True
            # 回溯
            buckets[i] -= select

def canPartition(link, sumV,m):
    # 分摊等和子集。
    if sumV % m !=0:
        return False
    subSum = sumV / m
    if subSum<link[0]:
        return False
    while len(link)>0 and link[0] == subSum:
        link.pop(0)
        m -= 1
    buckets = [0] * m
    return partition(link, 0, buckets, subSum)

def result(link, m):
    # 先排序
    link.sort()
    sumV = 0
    for ele in link:
        sumV += ele
    while m>=1:
        if canPartition(link[:],sumV, m):
            return int(sumV / m)
        m-=1
    return sumV

m = int(input())
link = list(map(int, input().split()))
print(m)
print(link)

result(link, m)


# 7
# 4 3 2 3 5 2 1
# 7
# [4, 3, 2, 3, 5, 2, 1]