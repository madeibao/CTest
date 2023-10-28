

k = int(input())
s = input()
# password__a12345678_timeout_100
print(k)
print(s)


def result():
    # 遍历s所有字符，用栈来解决
    stack = []
    res = []
    for c in s:
        # 如果c为"_" 前提下。要么栈为空，要么栈底为双引号。栈底为双引号，表示这个下划线是在双引号里面的。
        # 如果栈底不是双引号，那么这个下划线是命令的分隔符。
        if c == "_" and (len(stack) == 0 or stack[0] != '"'):
            res.append("".join(stack))
            stack = [] #清空栈。
        # 如果c为双引号",就要判断是左双引号，还是右双引号如果左双引号，栈为空，那么数据就要进栈。
        # 如果栈不为空，说明命令结束了。
        elif c == '"' and len(stack)!=0:
            stack.append(c)
            res.append("".join(stack)) # 命令也要加到res中。
            stack = []
        else:
            # 其他情况只能添加进栈
            stack.append(c)
    # 总是会忘记这个点，循环完之后，栈有空的或者不为空。假设最后一个没有遇到"_"栈里肯定有数据
    if len(stack)>0:
        res.append("".join(stack))
    # 一句话过滤掉为空的。
    ans = list(filter(lambda x:x !="", res))
    if k>len(ans)-1:
        return "ERROR"
    ans[k] = "******"
    return "_".join(ans)
print(result())