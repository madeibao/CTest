

# 输入处理
n, d = map(int, input().split())
arr = list(map(int, input().split()))


def getResutle(n, d, arr):
    arr.sort()
    diffs = []
    for i in range(1, len(arr)):
        diff = arr[i]-arr[i-1]
        if diff<=d: # 从小到大排序的，结果相邻两个差额都大于d了，肯定不能配对。
            diffs.append([i-1, i , diff]) # 有重复的 1,2配对，2和3配对。
    if len(diffs) == 0: return -1
    # return diffs
    # [[0, 1, 29], [2, 3, 0], [3, 4, 6], [4, 5, 2]]
    # 接下来处理重复配对的
    res = []
    dfs(0, diffs, [], res)
    res.sort(key=lambda x:(-x[0], x[1])) # 先看组合数，组合数最多， 如果组合数相同，看差最小。排序就是这样的。
    return res[0][1] # 返回的是和值最小的那个

def dfs(index, diffs, path, res):
    # 开始遍历
    for i in range(index, len(diffs)):
        if len(path)==0 or path[-1][1] < diffs[i][0]:# 把重复的去掉。
            path.append(diffs[i])
            dfs(i+1, diffs, path, res) # 牛掰。
            '''
            举个例子：
            [[0, 1, 29], [2, 3, 0], [3, 4, 6], [4, 5, 2]]  diffs 的下标为0，进去，那么下标为1的进去，2的肯定进不了。
            调用一次dfs 把指针往下移动一个，就会出现，下标为1的进，下标为2的不能进，等到dfs 的indx等于2的时候下标为2的肯定进去
            '''
            count = len(path) # 计算组合了多少个。
            sumDiff = sum(map(lambda x:x[2], path)) # 求出差别的和。
            # 添加到res里
            res.append([count, sumDiff])
            path.pop() # 这里没搞清

print(getResutle(n,d,arr))


'''


6 20
81 87 47 59 81 18

'''