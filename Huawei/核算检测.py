


import queue
 
# 输入获取
x, y = map(int, input().split())
arr = list(map(int, input().split()))
 
 
def getAdd(s):
    """
    :param s: 采样员对象
    :return: 假设采样员s增加一名志愿者能提升的效率
    """
    if s.volunteer == 0:  # 如果当前采样员没有志愿者，则新增一名志愿者可以提升base * 20%的效率
        return s.base * 0.2
    elif s.volunteer <= 3:  # 如果当前采样员搭配的志愿者数量小于等于3个，则说明再新增一个志愿者，可以提升base * 10%的效率
        return s.base * 0.1
    else:  # 如果当前采样员已有4个志愿者，则再新增一个志愿者，不能提升效率，即提升效率为0
        return 0
 
 
class Sampler:
    def __init__(self, volunteer, base):
        """
        :param volunteer: 该采样员搭配的志愿者人数
        :param base: 该采样员的基准效率
        """
        self.volunteer = volunteer
        self.base = base
        self.total = base * 0.8  # 初始时采样员没有搭配志愿者，则效率只有base*0.8
 
    def __lt__(self, other):
        return getAdd(self) > getAdd(other)  # 基于大顶堆排序，优先级为：增加一名志愿者能提升的效率
 
 
# 算法入口
def getResult(arr, x, y):
    """
    :param arr: 各采样员基准效率值（单位人/小时） [60, 600]
    :param x: 采样员人数 [1, 100]
    :param y: 志愿者人数 [1, 500]
    :return: 总最快检测效率（单位人/小时）
    """
 
    # 优先队列
    pq = queue.PriorityQueue()
 
    # 将所有采样员员加入优先队列，初始时采样员都不搭配志愿者
    for base in arr:
        pq.put(Sampler(0, base))
 
    # 只要还有志愿者，就将其分配给采样员
    while y > 0:
        # 如果堆顶采样员已有四个志愿者，那么该采样员能提升的效率为0，说明此时提升0的效率就是所有采样员中能提升的最大效率，即说明所有采样员都安排到了四个采样员，因此再增加志愿者也不会带来效率提升
        if pq.qsize() == 0 or pq.queue[0].volunteer == 4:
            break
 
        # 如果上一步不成立，则取出堆顶采样员
        s = pq.get()
 
        # 为其新增一个志愿者，并提升相应效率
        s.total += getAdd(s)
        s.volunteer += 1
 
        # 重新压入队列
        pq.put(s)
        y -= 1
 
    ans = 0
    while pq.qsize() > 0:
        ans += pq.get().total
 
    return int(ans)
 
 
# 算法调用
print(getResult(arr, x, y))