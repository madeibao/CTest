

import re
def result(s):
    '''
    ^	匹配字符串的开头
    $	匹配字符串的末尾。
    *	匹配0个或多个的表达式
    +	匹配1个或多个的表达式。
    ?	匹配0个或1个由前面的正则表达式定义的片段，非贪婪方式
    '''
    reg = re.compile(r"^(01)+0$")
    maxLen = 0
    ans = "-1"
    stack = []
    for c in s:
        if c == "0":
            # 栈不为空，并且栈顶元素为0，说明分割了
            if len(stack)>0 and stack[-1] == "0":
                tmp = "".join(stack) # 把栈拼起来，然后匹配
                # 看看有没有匹配上。
                if reg.match(tmp) is not None and len(stack)>maxLen:
                    maxLen = len(stack)
                    ans = tmp
                # 上面肯定是划分了串串了。不管有没有更新maxLen都要清理栈。
                stack.clear() # clear()后面有括号的。
        #不管是否等于0，都要入栈
        stack.append(c)
    # 搞完了，开始判断
    if len(stack)>0:
        tmp = "".join(stack)
        if reg.match(tmp) is not None and len(stack)>maxLen:
            return tmp
    return ans

print(result(s))



