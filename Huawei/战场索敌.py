

n, m, k = map(int, input().split())

# 3 5 2
# . . # E E
# E . # E .
# # # # . .

matrix = [input() for i in range(n)]
print(n, m, k)
print(matrix)


visited = [[False]*m for i in range(n)]
directs = ((-1, 0), (1, 0), (0, -1), (0, 1))
def bfs(i, j):
    cnt = 0
    # 如果对应的位置E,则敌军数量+1
    if matrix[i][j] == "E":
        cnt += 1
    visited[i][j] = True
    queue = [(i, j)]
    while len(queue)>0:
        # 广搜依赖队列结构，先进先出
        x, y = queue.pop(0)
        # 然后遍历该位置的上下左右
        for dirx, diry in directs:
            newX = x + dirx
            newY = y + diry
            # 位置不越界，且未访问过，且不是墙，则继续广搜
            if n>newX>=0 and m>newY>=0 and not visited[newX][newY] and matrix[newX][newY] != "#":
                if matrix[newX][newY] == "E":
                    cnt += 1
                # 标记该位置访问过
                visited[newX][newY] = True
                queue.append((newX, newY))
    return cnt


def result():
    ans = 0
    for i in range(n):
        for j in range(m):
            if visited[i][j] or matrix[i][j] == "#":
                continue
            ans += 1 if bfs(i, j)< k else 0
    return ans
print(result())