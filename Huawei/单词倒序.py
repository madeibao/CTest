

def result():
    # 去掉首尾空格
    chars = list(line.strip())
    stack = []
    start = 0 # 标记从哪个位置开始弹。
    for i, cur in enumerate(chars):
        # 遇到题目说的空格，疑问号，逗号，句号
        if cur in [" ", "?", ",", "."]:
            for j in range(start, i):
                # 把栈内的数据一个个弹出来。弹出来并且对应位置的元素要尽心改变。
                chars[j] = stack.pop()
            # start更新到i+1
            start = i+1
            if cur != " ":
                # 如果不等于空格，就是?,.三种符号,这个是不用翻转的。所以start还要加1。注意这个逻辑。
                start += 1
        else:
            # cur指针没有遇到要反转的字符标志，就直接入栈。
            stack.append(cur)
    # 妙啊，到这一步肯定栈里还有东西。弹出一个替换对应的位置。
    for j in range(start, len(chars)):
        chars[j] = stack.pop()
    return "".join(chars)


if __name__=="__main__":

    line = input()
    # yM eman si boB
    # woh era uoy ? I ma enif.
    print(line)
    print(result())


