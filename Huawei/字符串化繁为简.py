

s = input()
# (abd)demand(fb)()for
print(s)


def canCombine(set1, set2):
    for c in range(97, 123):
        # 小写字母97-122
        lowc = chr(c) # 小写字母
        # 大写字母65-90 
        upc = chr(c - 32) # 大写字母
        # 另外，同一个英文字母的大写字母和小写字母也相互等效(即使它们分布在不同的括号对里)。
        # 我们先把同一个大写，小写作为相等。比如a在set1里A在set2里，也能联通。
        # 咱们先不考虑大写或者小写。就a而言，a在set1里并且a在set2里，这两个set就能等效。
        # 然后把a换成(A或a) 即：(A或a) 在set1里，并且(A或a)在set2里。
        if (lowc in set1 or upc in set1) and (lowc in set2 or upc in set2):
            return True
        return False


def loop(eqs):
    # 把各个括号里的相互等效的，看能不能合并
    for i in range(len(eqs)):
        for j in range(i+1, len(eqs)):
            # 两个集合可以合并，就是存在相同的元素
            if canCombine(eqs[i], eqs[j]):
                tmp = list(eqs[i])
                tmp.extend(eqs[j]) # 把j的元素加到tmp里来
                eqs[i] = set(tmp)
                eqs.pop(j)
                return True
    return False

def result():
    cArr = []
    # 等效字符集合
    eqs = []
    # 有米有遇到(字符
    flag = False
    for i in range(len(s)):
        c = s[i]
        if c == "(":
            # 遇到了，就要把标记改成True
            flag = True
            # 字符要加入到等效字符里
        # 一个括号内的字符是互相等效的，但是不同括号内字符不一定等效。
        # 比如括号1（ab），括号2（cd），那么只能是a、b等效，c、d等效，如果只创建一个等效字符，
        # 则不好区分哪些字符是同一个括号的
            eqs.append(set()) # 初始化呗
        elif c == ")":
            # 遇到反括号，就要关闭了
            flag = False
            # 看用例，人家有()这种情况。所以要通过长度判断下。
            if len(eqs[-1]) == 0:
                eqs.pop()
        # 其他情况，加进来
        else:
            if not flag:
                # 如果括号没开启
                cArr.append(c)
            else:
                # 括号开启了，就要加到eqs的倒数第一个中去
                eqs[-1].add(c)
    # 暴力合并一波。将eqs里的所有set合并了一遍。
    while loop(eqs):
        pass
    # 开始替换主体字符容器的字符
    for eq in eqs: # 逐个遍历eqs的每一个set。这个时候里的set元素是不能合并的。
        tmp = list(eq) # 转化为list便于排序
        tmp.sort() # 排序
        t = tmp[0] # 根据题意拿到最小的。
        for i in range(len(cArr)): # 把非括号内的数据进行替换。
            if cArr[i] in eq: # 只要在set里的就替换成set里最小的值。
                cArr[i] = t
    ans = "".join(cArr)
    return "0" if len(ans) == 0 else ans
# s = 'z(AZ)'

print(result())