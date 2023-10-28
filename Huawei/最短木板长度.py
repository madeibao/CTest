

def result(n, m, a):
    lengths.sort() # 把木板先排序。
    # 统计长度，以长度为key，数量为value
    count = {}
    for ai in a:
        if ai not in count:
            count[ai] = 0
        count[ai] += 1
    
    arr = []
    for ai in count.keys():
        arr.append([int(ai), count[ai]])
    arr.sort(key= lambda x:x[0]) # 把版子排好序
    # 只要还有木板，就把他补到最短板上。
    while m > 0:
        # 如果只有一种板子的长度。分情况讨论，如果只有一种长度
        if len(arr) == 1:
            lenv, count = arr[0] # 拿到长度以及数量。
            return lenv + m//count
        # 接下来就是多种长度了
        min1 = arr.pop(0) # 队首弹出来。长度是最小的，
        min2 = arr[0] # 第二小的。
        # 看m能不能满足
        # 计算两者之间的差距
        diff = min2[0] - min1[0]
        # 计算填满min1所有板材到min2[0]的高度需要多少
        total = diff * min1[1]
        if total > m :
            return min1[0] + m//min1[1] # 把m均分到min1所有的木板
        elif total == m: # 把所有最短木板补齐到min2的长度，min2[1]就是答案
            return min2[0]
        else:
            # 补齐还有剩余
            # 更新m
            m -= total
            # 补齐之后，min2的木板数就增加了。
            min2[1]+=min1[1]
    return arr[0][0] # 返回队首元素的第一个值，就是长度


n,m = map(int, input().split())
lengths = list(map(int, input().split()))


# 算法调用
print(result(n, m, lengths))




