

import functools
def cmp(a, b):
    # 先按大小比
    if a[1] != b[1]:
        return b[1] - a[1]
    # 如果有访问次数相等的URL，按URL的字符串字典序升席排列，输出排序靠前的URL;
    elif a[0] != b[0]:
        return 1 if a[0]>b[0] else -1
    else:
        return 0


def sortURL(urls,cache,n):
    # 要求top几嘛
    for url in urls:
        if cache.get(url) is None:
            cache[url] = 1
        else:
            cache[url] += 1
    urlCount = list(cache.items())
    urlCount.sort(key=functools.cmp_to_key(cmp))
    return ",".join(map(lambda x:x[0], urlCount[:n])) # 本来就是str就不用转了

urls = []  # 记录输入的url
cache = {}  # 记录每个url出现的次数
ans = []  # 记录题解
while True:
    tmp = input()
    if tmp == "": # 打印结果的时候了
        for an in ans:
            print(an)
    if tmp.isnumeric():
        # 输入的是数字 如果输入的是数字，则需要对前面输入的url进行排序统计
        ans.append(sortURL(urls, cache,int(tmp)))
        urls = [] # 清空，要重新统计了
    else:
        urls.append(tmp)