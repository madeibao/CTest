


m, n = map(int, input().split())
arr = [list(map(int, input().split())) for i in range(m)]
print(m, n, arr)

# 每个节点可以向 8 个方向(上、下、左、右及四个斜线方向)
direct = ((-1,0), (1,0), (0,-1), (0,1),(-1,-1),(-1,1),(1,-1), (1,1))
def dfs(i, j, delay, last, path, res):
    '''
    i: 当前正在被 dfs 的节点的横坐标
    j: 当前正在被 dfs 的节点的纵坐标
    delay: 已累计的时延值
    last: 上一个节点的时延值，用于和当前节点时延值对比，若相同，则新增时延-1
    path: 记录扫描过的节点的位置，避免重复扫描
    res: 记录各种从起点到终点的路径的时延值
    '''
    # 当前节点的时延
    cur = arr[i][j]
    # 题目是这么说的连续两个相同时延可以减少一个时延值(即当有K 个相同时延的节点连续转发时可以减少 K-1 个时延值)
    # flag 用于标记，当前节点和上一个节点的时延值是否相同，若相同，则新增的时延值要-1
    flag = (cur == last)
    # # 如果搜索到了最后一个点，那么就将该路径的时延计算出来，加入到 res 中，结束分支递归
    if i == m-1 and j == n-1:
        delay += cur - (1 if flag else 0)
        return res.append(delay)
    # 开始深度搜索
    for dirx, diry in direct:
        new_i = i+dirx
        new_j = j+diry
        pos = new_i * m + new_j # m为行数，n为列数。
        if 0<=new_i<m and 0<=new_j<n and pos not in path:
            path.add(pos)
            # 当前节点和上一个节点的时延值是否相同，若相同，则新增的时延值要-1
            dfs(new_i, new_j, delay+cur - (1 if flag else 0), cur, path, res)
            # 然后就是回溯啦
            path.remove(pos)

def result():
    res = []
    path = set()
    # 初始时，[0,0]位置已被扫描，因此要将它的一维坐标形式，即 0 * m + 0，加入已扫描过的节点列表 path 中，避免重复扫描
    path.add(0)
    dfs(0,0,0,float("inf"), path, res)
    print(min(res))


result()
