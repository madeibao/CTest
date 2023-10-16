    




import functools
def cmp(a, b):
    if a[1] != b[1]: # 第一个是统计的数量。
        return b[1] - a[1]
    # 相等了，按照自然顺序进行排序，且小写字母在大写字母之前。
    # 同时大写，或者同时小写。
    if (a[0].islower() and b[0].islower()) or (a[0].isupper() and b[0].isupper()):
        return 1 if a[0]> b[0] else -1
    else:
        # 有个大写，有个小写。
        if a[0].isupper():
            return 1 # 大。
        else:
            return -1

def result():
    letter = {}
    for c in s:
        letter[c] = letter.get(c, 0) + 1 # 高级啊。
    letterList = list(letter.items()) # 把key，value搞出来。放到列表里。优秀
    letterList.sort(key=functools.cmp_to_key(cmp))
    return "".join(list(map(lambda x:f"{x[0]}:{x[1]};", letterList)))
result() 