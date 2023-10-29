
s = input()
# (1+(2+3)*(3+(8+0))+1-2)
print(s)


import re
def result(s):
    # 只要不是"("或者")"都改为"" re.sub 匹配替换为选择的文本。
    s = re.sub(r"[^\(\)]", "",s)
    # print(s)
    cnt = 0
    stack = []
    for c in s:
        # 下面要弹栈，就要判断栈是否为空。当前的字符要为反括号
        if len(stack) > 0 and c == ")":
            if stack[-1]  == "(":
                stack.pop()
                cnt += 1
                continue # 这里要加continue，符合情况要结束当前循环。
                # 不然走到下面的return -1了
            # 如果不匹配，那只能返回错误了
            return -1
        # 别忘了字符入栈
        stack.append(c)
    # 循环完了。要进行判断
    if len(stack)>0:
        return -1
    # 如果为空，说明匹配好了。
    return cnt 


print(result(s))
