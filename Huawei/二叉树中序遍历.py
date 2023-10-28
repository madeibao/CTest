

s = input()
print(s)
def result(s):
    idxs = [] # 用来记录{的位置
    stack = []
    for i in range(len(s)):
        c = s[i]
        if c == "}":
            print("更新stack前：",stack)
            idx = idxs.pop() # 处理逻辑
            root = stack[idx-1]
            left , right = "", ""
            tmp = "".join(stack[(idx+1):]).split(",")
            if len(tmp) == 1:
                # 节点没有右节点
                left = tmp[0]
            else:
                left, right = tmp # 如果左节点为空，因为初始化为空，所以也没影响。
            stack = stack[:(idx-1)] # 更新stack
            stack.append(left+root+right)
            print("更新stack后：",stack)
            continue # 这里加个continue结束循环
        if c == "{":
            idxs.append(len(stack)) # 妙啊。直接把-1去掉了。优秀
        stack.append(c) # 只有c == "}"情况，才不用入栈。其他都要入栈。
    return stack[0]
result(s)