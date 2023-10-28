
directs = ((1 ,0), (-1 ,0), (0 ,-1), (0 ,1))
def bfs(i, j):
    count = 1
    matrix[i][j] = 0
    queue = [[i ,j]] # 初始化队列
    while len(queue ) >0:
        x, y = queue.pop(0)
        for dirx, diry in directs:
            newX = x + dirx
            newY = y + diry
            # 边界条件的判断
            if n> newX >= 0 and m > newY >= 0 and matrix[newX][newY] == 1:
                count += 1
                matrix[newX][newY] = 0
                queue.append([newX, newY])
    return count


def result(n, m, matrix):
    ans = 0
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == 1:
                ans = max(ans, bfs(i, j))
    return ans


n, m = map(int, input().split())
matrix = [list(map(int, input().split())) for i in range(n)]
# print(n, m)
# print(matrix)
print(result(n, m, matrix))