

s = input()
print(s)


s='3[m10[cd]]'
def result(s):
    stack = []
    repeat = []
    for c in s:
        # 
        # if c.isdigit():
        #     # 如果是数字，就把他放到repeat里去
        #     repeat.append()
        if c == "]":
            tmp = ""
            while len(stack) > 0 and stack[-1] != "[":
                tmp += stack.pop()
            # 弹栈遇到了[了
            # tmp就是要重复的值了
            res = tmp[::-1]
            if len(stack)>0 and stack[-1] == "[":
                stack.pop() # 把[弹出来。
                while len(stack)>0 and ord('0')<=ord(stack[-1])<=ord('9'):
                    repeat.append(stack.pop())
                num = int("".join(map(str,repeat[::-1])))
                repeat = [] # 把repeat 置空，用来统计下一个。
                # 算完之后要压入栈中。
                stack.extend(res*num)
            continue # 反正]是不能加入stack里的。
        stack.append(c)
    return "".join(stack)


print(result(s))