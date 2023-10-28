
m, n = map(int, input().split())
# 可以同行的
want = [list(input().split()) for i in range(m)]
# 禁止同行的
cant = [list(input().split()) for i in range(n)]
# 4 2
# package1 A C
# package2 A C
# package3 B C
# package4 A C
# A B package1
# A C package2
print(m, n)
print(want)
print(cant)


def result():
    '''
    want:元素含义：[包裹，起始点，目的点]
    cant:元素含义：[起始点，目的点, 无法通过的货物列表]
    '''
    wantDict = {}
    cantDict = {}
    # 统计want
    for arr in want:
        package, src, dst = arr
        path = f"{src}-{dst}"
        if wantDict.get(path) is None:
            wantDict[path] = [package]
        else:
            wantDict[path].append(package)
    # 统计cant
    for arr in cant:
        # 这里要注意，packages！
        src, dst, packages = arr[0], arr[1], arr[2:]
        path = f"{src}-{dst}"
        if cantDict.get(path) is None:
            cantDict[path] = packages[:] # 复制一份。
        else:
            cantDict[path].extend(packages) # 注意这里是extend哟！！！
    ans = []
    for path in wantDict.keys():
        if cantDict.get(path) is None:
            continue
        wantPKG = set(wantDict[path])
        cantPKG = set(cantDict[path])
        for pkg in wantPKG:
            if pkg in cantPKG:
                ans.append(pkg) # 把不通的加进去了
    if len(ans)>0:
        ans.sort(key= lambda x:int(x[7:])) # 优秀，通过这个来排序。
        return " ".join(ans)
    else:
        return "none"
print(result())

