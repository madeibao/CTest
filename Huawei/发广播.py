

matrix = input().split(",")
print(matrix)

class UnionFind:
    def __init__(self,n):
        self.fa = list(range(n))
        self.c=n
    def find(self, val):
        if self.fa[val] == val : return val
        self.fa[val] = self.find(self.fa[val])
        return self.fa[val]
    def merge(self, x, y):
        x_r = self.find(x)
        y_r = self.find(y)
        if x_r != y_r:
            self.fa[y_r] = x_r
            self.c -= 1
def result():
    n = len(matrix)
    uf = UnionFind(n)
    for i in range(n):
        for j in range(i+1, n):
            if matrix[i][j] == "1":
                uf.merge(i, j)
    return uf.c

print(result())