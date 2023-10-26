


import re
s = input()
# 好好去复习下re模块吧。用到啥就搞啥吧。
# A={1,3,5},B={2,4,6},R=1
# . 匹配除换行符  \n 之外的任何单字符 
# +	匹配前面的子表达式一次或多次。要匹配  + 字符，请使用 +
# *	匹配前面的子表达式零次或多次。要匹配  * 字符，请使用 *
# ?	匹配前面的子表达式零次或一次，或指明一个非贪婪限定符。要匹配  ? 字符，请使用 \?
# compile 函数用于编译正则表达式，生成一个 Pattern 对象，它的一般使用形式如下
tmp = re.compile(r"A=\{(.+)},B=\{(.+)},R=(.+)").search(s)
A = list(map(int, tmp.group(1).split(",")))
B = list(map(int, tmp.group(2).split(",")))
R = int(tmp.group(3))
print(A)
print(B)
print(R)


# 最新的算法
def result():
    ans = []
    for a in A:
        cnt = 0
        for b in B:
            if b < a:
                continue
            # 到这里b>=a 然后判断，要么b-a<=R,如果>R,并且计数为0就找到了
            if b-a<=R or cnt == 0:
                ans.append(f"({a},{b})")
                cnt += 1
            # 等到下一个b-a>R运行到这里，就会结束循环。
            else:
                break
    return "".join(ans)
print(result())