

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


s = input()
# s="(((){{()[]}}))"
def result():
    map = {")":"(", "]":"[", "}":"{"}
    stack = [s[0]] # 初始化栈
    maxDepth = 0
    depth = 0
    # 只有出现了) ] }才能统计深度嘛。
    for i in range(1, len(s)):
        c = s[i]
        if map.get(c) is not None and map[c] == stack[-1]:
            stack.pop() # 弹出来，消掉一层。
            depth += 1
            maxDepth = max(maxDepth, depth)
        else:
            depth = 0 # 这个要好好理解下。就是他是靠最里边的。
            '''
            "(((){{()[]}}))"
            他是靠最后面的]}}))来判断深度。而不是靠中间的某个)这种来判断。所以要把他置零。不然就累加了。
            '''
            stack.append(c) # 把depth 重置为0
    if len(stack)>0: # 搞了半天你这个站还要元素，没匹配成功啊。
        return 0
    return maxDepth


print(result())
