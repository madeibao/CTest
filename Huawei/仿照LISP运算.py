

import math
def oper(op, p1, p2):
    p1 = int(p1)
    p2 = int(p2)
    if op == "add":
        return str(p1+p2)
    elif op == "sub":
        return str(p1-p2)
    elif op == "mul":
        return str(p1*p2)
    elif op == "div":
        if p2 == 0:
            return "error"
        else:
            # return str(p1//p2)
            return str(int(math.floor(p1 / p2)))
    else:
        return "error"
    
def result():
    stack = []
    leftIdxs =[]
    for i in range(len(s)):
        if s[i] == ")":
            l = leftIdxs.pop() # 找到栈里最近的"("
            fragment = stack[l:] # 截取片段。
            del stack[l:] # 在栈中删除。
            # fragment[0] = "("
            # 这里fragment是list，所以要拼接下。然后再用
            print("fragment:", fragment)
            op, p1, p2 = "".join(fragment[1:]).split(" ")
            res = oper(op, p1, p2)
            if res == "error":
                return "error"
            else:
                print("res:", res)
                stack.extend(list(res)) # 不就是一个字符嘛，还要转化为列表，然后还要list下？
        elif s[i] == "(":
            # 等于"(" 要记录当前的位置啊
            leftIdxs.append(len(stack)) # 把当前长度加上去，这样的话他刚好下标加1
            stack.append(s[i])
        else:
            stack.append(s[i])
    return "".join(stack)
# s='(div 12 (sub 45 45))' # 输出'error'
s = '(add 1 (div -7 3))'
result()