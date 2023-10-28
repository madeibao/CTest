# s = '{A3B1{C}3}3'
# s = '{AD11B1{CF}3}3'
def result(s):
    stack = [] # 栈，所有的数据进入栈中。
    idxs = [] # 用来存{的位置。这里是存在栈里的位置。而不是别的位置。
    repeat = [] # 用来存重复次数。
    s = s + " "
    for c in s:
        if c.isdigit(): # 为什么先搞数字，因为数字搞完之后下一步如果不是数字，就可以把上面的重新计算了。
            # 如果是数字
            repeat.append(c)
            continue # 一句continue 就把数字的不入栈了。
        if len(repeat)>0:
            n = int("".join(repeat)) #优秀，直接把他转化为int类型。
            repeat = [] # 然后把repeat置空。
            top = stack.pop() # 弹出来，
            if top == "}":
                # 就要找到{在哪里
                start = idxs.pop() # idxs最后一个，存的就是与}最近的一个。
                frag = "".join(stack[start+1:]) # 因为}已经弹出来了，所以就直接到末尾了
                stack = stack[:start] # 因为start的位置是{,所以取不到嘛。
                print("出现}， extend前：", stack)
                stack.extend([frag] * int(n))
                print("出现}， extend后：", stack)
            else:
                print("没有}， extend前：", stack)
                stack.extend([top]*int(n)) #别忘了，这个数字只对紧邻的字符放大多少倍，
                print("没有}， extend后：", stack)
        if c == "{":
            idxs.append(len(stack)) # 因为idxs是要+1的。所以刚好len(stack)加了1
            print("出现了{ :", idxs)
        stack.append(c)
    return "".join(stack).strip() # 默认情况下，函数strip()将删除字符串开头和结尾的空格，并返回前后不带空格的相同字符串。

s = input()
print(result(s))