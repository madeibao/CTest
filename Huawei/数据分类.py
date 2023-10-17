


# 判断是否有效
def classify(a):
    s = hex(a)[2:] # hex 方法会将十进制转为 0x 开头的 16 进制数，这里去除 0x 前缀
    if len(s) % 2!=0:
        s = "0"+s # 前面补0
    sumV = 0
    for i in range(0, len(s)-1, 2):
        sumV += int(s[i: i+2], 16) # 按照16进制来计算。
    t= sumV %b
    # 如果得到的结果小于一个给定的值C，则数据a为有效类型
    if t<c:
        return t
    # 其类为取模的值;如果得到的结果大于或者等于c，则数据a为无效类型
    else:
        return -1

# 算法入口
def result():
    count = {}
    for t in map(classify, arr):
        # 这个写法好棒，很高级。
        if t!=-1:
            if count.get(t) is None:
                count[t] = 1
            else:
                count[t] += 1
    return max(count.values())
result()