


m, n = map(int, input().split())
# 5 3
# 1 2 6
nums = list(map(int, input().split()))
print(m, n)
print(nums)



# 上升序列组合的元素个数
expectUpCount = 0
# 上升序列组合的元素之和的上限
limitUpSum = 0
# 如果不能到达楼层，给出小于该楼层的最近序列组合。
# 记录不超过limitUpSum的最大的上升序列的和，该变量用于帮助ans剔除不是最优解的上升序列
maxUpSumBelowLimit = 0
#  paths记录求组合过程中发现的符合要求的序列
paths = []

def getSeq(path):
    # 上升序列
    up = []
    # 下降序列
    down = []
    # 根据path的True，False来判断
    for i in range(n):
        if path[i]:
            up.append(nums[i])
        else:
            down.append(nums[i])
    # 目标容器
    seq = []
    # 交叉合并
    for i in range(n//2):
        seq.append(up.pop(0))
        seq.append(down.pop(0))
    # 还剩一个。(数列为奇数嘛)
    if len(up)>0:
        seq.append(up.pop(0))
    return seq


def dfs(index, path, total, count):
    """
    该方法用于选取出上升序列的组合
    index: 当前层级能选取的元素范围的起始索引
    path: 记录上升序列组合，注意path这里采用的是len()长度的boolean[]数组，
    如果path[i]为true，则代表nums[i]是上升，否则nums[i]就是下降
    total: 上升序列组合的元素和
    count: 上升序列组合的元素个数
    """
    global maxUpSumBelowLimit
    # 如果上升序列元素个数超过了expectUpCount, 则结束对应递归
    if count > expectUpCount:
        return 
    # 如果上升序列元素个数刚好就等于expectUpCount, 有可能是答案。
    if count == expectUpCount:
        # 非更优解，直接剔除
        if total < maxUpSumBelowLimit:
            return
        # 发现更优解，就要清空paths
        if total > maxUpSumBelowLimit:
            maxUpSumBelowLimit = total
            paths.clear()
        # 记录对应解
        paths.append(path[:])
        return
    for i in range(index, n):
        if total + nums[i] > limitUpSum:
            # 上多了
            continue
        path[i] = True # 当前改为上。
        dfs(i+1, path, total+nums[i], count+1)
        # 回溯
        path[i]=False 

def result():
    global expectUpCount
    global limitUpSum
    # 计算expectUpCount、limitUpSum
    expectUpCount = n//2 + n%2 # 偶数个，上升的数量就是n//2，奇数个就是 n//2 + 1妙啊
    limitUpSum = (sum(nums)+m) // 2
    # 升序排列
    nums.sort(reverse=True)
    # 求组合数
    dfs(0, [False]*n, 0, 0)
    # 本题没有说明异常处理，我理解应该不会存在paths.size == 0的情况，但是为了保险，还是处理一下
    if len(paths) == 0:
        return "-1"
    # 首先将paths转化为结果序列，然后对结果序列进行排序，排序规则是：按先处理大值的原则, 最后取出最优解
    seqs = list(map(lambda path: getSeq(path), paths))
    seqs.sort(reverse=True)
    return " ".join(map(str, seqs[0]))
print(result())