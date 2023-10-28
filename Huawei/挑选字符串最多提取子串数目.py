

a = input() # 
b = input()
print(a)
print(b)


def result(a, b):
    # 其中 a可能存在重复字母
    # B 不会存在重复字母
    # idxs 对象记录字符串 b 中每个字符的索引
    idxs = {} # bac{b:0, a:1, c:2}
    for i in range(len(b)):
        idxs[b[i]] = i # 题目说了，b上面是没有重复的元素的。
    # count 对象用于记录遍历字符串 a 每个字符串过程中，统计到的符合顺序要求的字符串b中字符出现次数
    count = [0] * len(b)
    for c in a:
        # 取的到值就去得到。取不到就位None
        idx = idxs.get(c)
        # 取到值，要么为0最大的，就只管加，或者count[idx]<count[idx-1]
        if idx is not None and (idx == 0 or count[idx]<count[idx-1]):
            count[idx] += 1
    return count[-1]


print(result(a,b))