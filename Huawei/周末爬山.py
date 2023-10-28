directs = ((1,0), (-1,0), (0,-1), (0,1))
def bfs(minStep):
    visited = [[False]*n for i in range(m)] # m行，n列
    # 广搜队列
    queue = [(0, 0)]
    # 初始化
    visited[0][0] = True
    step = 0
    while len(queue)>0:
        newQueue = [] # 用来装新节点的
        step += 1 # 这里是新节点的高度。
        # 遍历同一层的节点。
        for x, y in queue:
            # 拿到节点的值
            lastHeight = arr[x][y]
            # 开始广搜
            for dirx, diry in directs:
                newX = x + dirx
                newY = y + diry
                # 新的点边界条件的判断， 不越界，并且没有被访问过。
                # if newX>=m or newX<0 or newY>=n or newY<0:
                #     continue
                # if visited[newX][newY]:
                #     continue
                if m>newX>=0 and n>newY>=0 and not visited[newX][newY]:
                    # 拿到当前高度
                    curHeight = arr[newX][newY]
                    if abs(curHeight - lastHeight) <=k:
                        # 可以选择该点。
                        visited[newX][newY] = True
                        # 然后来算步数。
                        if minStep.get(curHeight) is None or minStep[curHeight] > step:
                            # 注意，这是新节点的高度。而不是在队列里的高度。
                            minStep[curHeight] = step
                        # 新位置加入广搜，跟更不更新step没关系。
                        newQueue.append((newX, newY))
        # 用新队列替换老队列
        print(newQueue)
        queue = newQueue

def result():
    # key表示到达山峰的高度，value用来记录到达这个高度的最短路径。
    minStep = {}
    # 初始化，到达arr[0][0]高度的最短步数肯定是0
    minStep[arr[0][0]] = 0
    # 广搜一波
    bfs(minStep)
    # 获得最大高度
    maxHeight = max(minStep.keys())
    print(minStep)
    # 得到最短步数
    ansStep = minStep[maxHeight]
    return f"{maxHeight} {ansStep}"


m, n, k = map(int, input().split()) # m行，n列，k爬上或下山的最大台阶数
# 5 4 1
# 0 1 2 0
# 1 0 0 0
# 1 0 1 2
# 1 3 1 0
# 0 0 0 9
arr = [list(map(int, input().split())) for i in range(m)]
print(m, n, k)
print(arr)

print(result())