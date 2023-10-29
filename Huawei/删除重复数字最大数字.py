


s = input()
print(s)

def result(s):
    # 每个数字字符的可用个数
    unused = {}
    # 每个数字字符的保留个数
    reserve = {}
    for c in s:
        if unused.get(c) is None:
            unused[c] = 0
        if reserve.get(c) is None:
            reserve[c] = 0
        unused[c] += 1
    # print(unused)
    # 上面算出来了每个字符有多少个。
    # 定义一个栈
    stack = []
    # 遍历输入字符串的每个数字字符 c
    for c in s:
        # 如果该字符已经保留了 2 个了，则后续再出现该数字字符可以不保留
        if reserve[c] == 2:
            continue
        # 比较当前数字 c 和栈顶数字 top，如果 c>top，那么需要考虑将栈顶数字弹出
        while len(stack) > 0:
            top = stack[-1]
            # 如果栈顶数字被弹出后，已保留的 top 字符数量和未使用的 top 字符数量之和大于等于 2，则可以弹出，否则不可以
            if top < c and unused[top] + reserve[top]-1 >= 2:
                stack.pop()
                reserve[top] -= 1
            else:
                break
        # 选择保留当前遍历的数字 c
        stack.append(c)
        # 则可用 c 数字个数--
        unused[c] -= 1
        # 已保留 c 数字个数++
        reserve[c] += 1
    return "".join(stack)

print(result(s))

