n = int(input())
'''
5
2019-01-01 00:00:00.004
2019-01-01 00:00:00.004
2019-01-01 00:00:01.006
2019-01-01 00:00:01.006
2019-01-01 00:00:01.005
'''
# 2019-01-01 00:00:00.004
arr = list(input() for i in range(n))
print(arr)


def result2():
    arr.sort(reverse=True) # 先来个降序排列。
    stack = [arr.pop()] # 把队尾元素入栈。
    while len(arr)>0:
        time = arr.pop()
        top = stack[-1]
        # 如果栈顶 跟现在time相等，也就是同一秒种，然后.001这个数字也相等。
        # 或者top[:19] 比如 2019-01-01 00:00:01 前面不相等。相当于另一秒了呀。别忘了arr是降序排列的。
        if top == time or top[:19] != time[:19]:
            stack.append(time)
    return len(stack)


print(result2())

