

n = 64
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# g 表示图形
g = [[0] * n for i in range(n)]

# nums 表示所有出现在 g 中的值
nums = []

m = int(input())
for i in range(m):
    lst = list(map(int, input().split()))
    nums.append(lst[0])
    for j in range(1, len(lst), 2):
        # 给对应的格子赋值
        g[lst[j]][lst[j + 1]] = lst[0]

# 统计每个值的周长之和
val = {}
for i in range(n):
    for j in range(n):
        # 当一个格子有值，才可能有边长
        if g[i][j] > 0:
            v = g[i][j]
            res = 4
            for k in range(4):
                nx, ny = i + dx[k], j + dy[k]
                if 0 <= nx < n and 0 <= ny < n and g[nx][ny] == v:
                    res -= 1
            val[v] = val.get(v, 0) + res

for i in range(m):
    print(val[nums[i]], end="\n" if i + 1 == m else " ")
