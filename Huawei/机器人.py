


'''
4 4
1 2 5 2
2 4 4 5
3 5 7 1
4 6 2 4



2 3
1 3 5
4 1 3


'''


m,n = map(int, input().split()) # m为行号，n为列号
arr = [list(map(int, input().split())) for i in range(m)]
print(m, n)
print(arr)


class UnionFind():
    def __init__(self, n) -> None:
        self.father = list(range(n))
        self.count = n

    def find(self, val):
        if self.father[val] == val:
            return val
        self.father[val] = self.find(self.father[val])
        return self.father[val]

    def merge(self, x, y):
        x_root = self.find(x)
        y_root = self.find(y)
        if x_root != y_root:
            self.father[y_root] = x_root
            self.count -= 1


uf = UnionFind(m * n)
directs = ((-1, 0), (1, 0), (0, -1), (0, 1))
for i in range(n):
    for j in range(m):
    # 注意下面这层 for 是常量级的，就四次循环，因此，这里的时间复杂度还是 O(n*m)，即
        for dirx,diry in directs:
            new_x = dirx + i
            new_y = diry + j
            if 0 <= new_x < n and 0 <= new_y < m and abs(arr[i][j] - arr[new_x][new_y]):
                uf.merge(i*n+j, new_x*n+new_y)

# ufs.count 是连通分量的个数，如果只有一个连通分量，那么代表所有的点都可达
if uf.count == 1:
    print(m * n)
else:
    # count 字典用于统计指向同一个祖先下点的个数，即每个连通分量下的点个数
    count ={}
    for i in range(m * n):
        uf.find(i)
        father = uf.father[i]
        count[father] = count.get(father, 0)+ 1
    # 取最大值。
    print(max(count.values()))


