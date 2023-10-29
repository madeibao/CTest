

n = int(input())
arr = [list(map(int, input().split())) for i in range(n)]
print(n)
print(arr)

class UnionFind():
    def __init__(self,n):
        self.father = list(range(n))
        self.count = n
    def find(self, val):
        if self.father[val] == val: return val
        self.father[val] = self.find(self.father[val])
        return self.father[val]
    def merge(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x != root_y:
            self.father[root_y] = root_x
            self.count-=1 # 合并的时候就把数量减去1

uf = UnionFind(n)

for i in range(n):
    for j in range(i+1, n):
        if arr[i][j] == 1:
            uf.merge(i, j)
print(uf.count)