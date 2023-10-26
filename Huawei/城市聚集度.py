import sys
# 输入
n = int(input())
# 5个节点，连接肯定只有4个啦。
relations = [list(map(int, input().split())) for i in range(n-1)]
print(relations)


# 先搞出并查集
class UnionFind:
    def __init__(self,n):
        self.father = list(range(n))
        self.count = n
    def find(self,val):
        if self.father[val] == val : return val
        self.father[val] = self.find(self.father[val])
        return self.father[val]
    def merge(self, x, y):
        x_root = self.find(x)
        y_root = self.find(y)
        if x_root != y_root:
            self.father[y_root] = x_root
            self.count -= 1

def result(n, relations):
    minV = sys.maxsize
    city = []
    # 遍历每个城市
    for i in range(1, n+1):
        uf = UnionFind(n+1)
        for x, y in relations: 
            # 切断 城市i的左右链接。
            # print(x, y)
            if x == i or y == i:
                continue
            # 其他情况的就合并
            uf.merge(x,y)
        # 开始统计合并后的顶点
        count = {}
        for x in uf.father:
            f = uf.find(x)
            if count.get(f) is None:
                count[f] = 1
            else:
                count[f] += 1
        # 用来统计城市群的数量。
        tmp = list(count.values())
        # 给值倒序排列下，取最大的
        tmp.sort(reverse=True)
        dp = tmp[0]
        if dp<minV:
            minV = dp
            city = [i]
        elif dp == minV:
            city.append(i)
    return " ".join(map(str, city))

print(result(n, relations))