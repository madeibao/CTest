m, n = map(int, input().split())
matrix = [list(map(int, input().split())) for i in range(m)]
'''
6 6
1 1 1 1 1 1
1 5 1 1 1 1
1 1 1 1 1 1
1 1 1 1 1 1
1 1 1 1 5 1
1 1 1 1 1 1
'''
print(m, n)
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
    brands = []
    # 找到所有的5
    for i in range(m):
        for j in range(n):
            if matrix[i][j] == 5:
                brands.append((i, j))
    k = len(brands)
    # 边界条件的判断，要么为0，要么全是
    if k == 0 or k == n*m:
        return 0
    uf = UnionFind(k)
    # 如果abs(x2 - x1) <= 3 and (y2 - y1) <= 3就可以合并，没有边界。
    for i in range(k):
        x1, y1 = brands[i]
        for j in range(i+1, k):
            x2, y2 = brands[j]
            if abs(x2 - x1) <= 3 and (y2 - y1) <= 3:
                uf.merge(i, j)
    return uf.c
    

print(result())

