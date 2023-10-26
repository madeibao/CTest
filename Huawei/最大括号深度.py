


s = input()
# s="(((){{()[]}}))"
def result():
    map = {")":"(", "]":"[", "}":"{"}
    stack = [s[0]] # 初始化栈
    maxDepth = 0
    depth = 0
    # 只有出现了) ] }才能统计深度嘛。
    for i in range(1, len(s)):
        c = s[i]
        if map.get(c) is not None and map[c] == stack[-1]:
            stack.pop() # 弹出来，消掉一层。
            depth += 1
            maxDepth = max(maxDepth, depth)
        else:
            depth = 0 # 这个要好好理解下。就是他是靠最里边的。
            '''
            "(((){{()[]}}))"
            他是靠最后面的]}}))来判断深度。而不是靠中间的某个)这种来判断。所以要把他置零。不然就累加了。
            '''
            stack.append(c) # 把depth 重置为0
    if len(stack)>0: # 搞了半天你这个站还要元素，没匹配成功啊。
        return 0
    return maxDepth


print(result())
