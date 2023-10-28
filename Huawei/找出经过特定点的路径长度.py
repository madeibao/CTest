

all = input()
must = input()
# ANTSEDXQOKPUVGIFWHJLYMCRZB
# ABC
print(all)
print(must)


import sys
def dfs(index, must, mustIdx, path, ans):
    # index用来标记在must的位置，path为路径。
    # 终止条件
    if len(path) == len(must):
        # 假设运动起点必须从第一行输入all的第一个字母开始。
        dis = path[0]
        for i in range(1, len(path)):
            dis += abs(path[i]-path[i-1]) # 这里要取绝对值哦。
        ans[0] = min(ans[0], dis) # 在添加进ans的时候就要比较哪个大。
        return # 注意这里为啥ans是个数组而不是个数字呢，我想着是后面回溯的时候要进行回退。
    # 开始index往后走，增加path
    for i in range(index, len(must)):
        idxs = mustIdx[must[i]] # 对应must[i]所有在all里边的idxs都取出来。
        # 开始遍历。
        for idx in idxs:
            path.append(idx)
            # 添加完一个之后，进行递归计算
            dfs(i+1, must, mustIdx, path, ans)
            # 回溯
            path.pop()


def result():
    mustIdx = {} # 把每个字符出现的id统计出来
    musChar = set(must)
    for i in range(len(all)):
        c = all[i]
        if c in musChar:
            if mustIdx.get(c) is None:
                mustIdx[c] = []
            mustIdx[c].append(i)
    ans = [sys.maxsize]
    dfs(0, must, mustIdx, [], ans)
    return ans[0]


print(result())


# ANTSEDXQOKPUVGIFWHJLYMCRZB
# ABC