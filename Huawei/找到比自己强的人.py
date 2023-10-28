

relations = eval(input())
# [[1,4],[1,3],[2,4],[2,1],[3,2]]
print(relations)


def getHighC(fa, f, src, highC):
    '''
    fa:用于统计每个师傅名下的直接徒弟排名，fa为师傅的排名，value是直接徒弟的排名
    f：当前的是否，初始时为源头祖师爷
    src：源头祖师爷
    highC 比源头祖师爷排名高的徒弟的排名集合
    return：比源头祖师排名高的徒弟排名的个数
    '''
    # 如果当前是否是第一名，肯定没有徒弟高于他了。所以直接返回0
    if f == 1:
        return 0
    for c in fa[f]:
        # 遍历当前师傅的所有徒弟
        flag = True # 标记是否要统计间接徒弟，默认需要
        # 如果徒弟的排名高于源头祖师，排名越高，值越小，那么应该统计到highC里
        if c < src:
            # highC集合中没有这个徒弟，就要统计，并要统计间接徒弟
            if c not in highC:
                highC.add(c)
            # 如果highC中已经有了当前的徒弟，则说明当前徒弟已经统计过了，
            # 不需要再统计，且当前徒弟的徒弟也不需要再统计了
            else:
                flag = False
        # 形成环，需要打断
        elif c == src:
            return 0
        # flag没有变，说明徒弟当时没有在highC中，所以要继续统计他徒弟的徒弟
        if flag:
            # 传参：fa不变 f变成c了，src，highC 没变。
            getHighC(fa, c, src, highC)
    return len(highC)

def result():
    # fa用于统计每个师傅名下的直接徒弟的排名,key表示师傅的排名，value表示徒弟的排名
    fa={}
    for f, c in relations:
        if fa.get(f) is None:
            fa[f] = [c]
        else:
            fa[f].append(c)
        # 如果徒弟没有，也要把它建立起来。
        if fa.get(c) is None:
            fa[c] = []
    ans = []
    # 遍历每一个师傅，然后去找比师傅高的徒弟的数量。
    for f in fa:
        ans.append([f, getHighC(fa, f, f, set())])
    # 按照师傅排名升序后，输出高于师傅排名的徒弟的个数
    ans.sort(key= lambda x:x[0])
    return list(map(lambda x:x[1], ans))
print(result())