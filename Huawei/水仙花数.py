

import math
def result(n, m):
    # 题目的边界判断
    if n<3 or n>7:
        return -1
    powN = {}
    # 每个位数，他对应的n次方算出来，后面只用查表就好了。
    for i in range(10):
        powN[str(i)] = int(math.pow(i, n))
    minV = int(math.pow(10, n-1)) # 左闭右开区间。
    maxV = int(math.pow(10, n))
    ans = -1 # 初始化有讲究的，默认是他返回错误的值。更新了就说明没问题，没更新，就直接返回他。
    count = -1 # 这里为啥呢，就是题目说了返回长度是n的第m个水仙花数。个数从0开始编号
    for i in range(minV, maxV):
        # 先把每个数转化为字符，然后在用powN做映射，映射完了求和。
        sumV = sum(map(lambda x:powN[x], list(str(i))))
        if sumV == i: # 你看i的两个作用用在一起了吧。
            ans = i # 用来记录当前值。碰到count = m就可以返回了。
            count += 1
            if count == m:
                return ans
    return ans


n= 3
m=0
print(result(n, m))