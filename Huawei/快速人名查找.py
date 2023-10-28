names = input().split(",")
# zhang san san,zhang an sa,zhang hang,zhang seng,zhang sen a
# zhas
abbr = input()
print(names)
print(abbr)


def dfs(parts, index, abbr, start):
    # index用来标记parts的位置，start 用来标记abbr的位置。
    if start >= len(abbr):
        # start快越界了。index应该也要越界。不然就有问题。
        return index >= len(parts) # 进来之前就保证了len(parts)<=len(abbr)
    for i in range(index, len(parts)):
        part = parts[i] # 比如 zhang
        # 本part匹配，马上让位于下一个。
        for j in range(len(part)):
            # start没有越界，并且part[j] == abbr[start]
            if start < len(abbr) and part[j] == abbr[start]:
                start += 1
                # 马上深搜一波 这里start+1，所以在递归的时候不用加了。
                res = dfs(parts, i+1, abbr, start)
                if res:
                    return True
            else:
                return False
    # 都搜了一圈了，
    return False


def result():
    ans = []
    for name in names:
        parts = name.split() # 比如这样的 'zhang san san'
        # 边界条件判定，len(parts)>len(abbr),因为题目说了一定要用到每个单词
        if len(parts) > len(abbr):
            continue
        res = dfs(parts, 0, abbr, 0)
        if res:
            ans.append(name)
    print(",".join(ans))
result()