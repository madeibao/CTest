

s = input()
# (1+2)/(0.5+1)
def result():
    map = {")":"(", "]":"[", "}":"{"}
    stack = [s[0]] # 初始化栈
    for i in range(1, len(s)):
        c = s[i]
        if map.get(c) is not None and map[c] == stack[-1]:
            stack.pop() # 弹出来，消掉一层。
        else:
            if c in ["(","[","{"]:
                stack.append(c) 
    if len(stack)>0: # 搞了半天你这个站还要元素，没匹配成功啊。
        return "false"
    return "true"


print(result())



