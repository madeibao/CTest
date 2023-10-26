


4
1 1 0 0
1 1 1 0
0 1 1 0
0 0 0 1
4 [[1, 1, 0, 0], [1, 1, 1, 0], [0, 1, 1, 0], [0, 0, 0, 1]]

#------------------------------------------------------------
3


class UnionFind():
    def __init__(self, n):
        self.father = list(range(n))
        # 本题要加个计数功能。
        self.count = n
    def find(self,val):
        if self.father[val] == val : return val
        self.father[val] =self.find(self.father[val])
        return self.father[val]
    def merge(self, x ,y):
        x_root = self.find(x)
        y_root = self.find(y)
        if x_root != y_root:
            self.father[y_root] = x_root



# 输入处理
n = int(input())
isConnected=[list(map(int, input().split())) for _ in range(n)]
# print(n, isConnected)

uf = UnionFind(n)
for i in range(n):
    for j in range(i+1, n): # j 从i+1开始，因为矩阵是对称的
        if isConnected[i][j] == 1:
            uf.merge(i, j)

ans = 1
for i in range(n):
    if uf.find(i) == i:
        ans += 1
print(ans)