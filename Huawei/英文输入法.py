


s = input()
pre = input()
print(s)
'''
The furthest distance in the world, Is not between life and death, But when I stand in front of you, Yet you don't know that I love you.
f
'''
print(pre)


import re
def result():
    tmp = re.split("[^a-zA-Z]", s) # 非大小写字母，就是分隔符。
    cache = list(set(tmp))
    cache.sort()
    # 把前缀过滤出来
    cache = list(filter(lambda x:x.startswith(pre), cache))
    if len(cache) == 0:
        return pre
    else:
        # len(cache) != 0
        return " ".join(cache)
print(result())