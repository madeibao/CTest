s = input()
# bAaAcBb
print(s)

def result():
    global s
    # 不区分大小写
    s = s.lower()
    # 统计出来每个字母出现的次数
    count = {}
    letters = [] # 去重字符串中的非字母
    for c in s:
        if "z">= c >= "a":
            # 统计字符串
            count[c] = count.get(c, 0) + 1
            letters.append(c)
    s = "".join(letters) + " " # 加空格是为了避免后续的收尾操作
    count[" "] = 1
    # 记录连续字母和非连续字母
    ans = []
    # 上一个字母的位置
    pre=s[0]
    # 该字母的连续次数， 初始化为1
    repeat = 1
    # 后续该字母还有count[pre] -= 1
    count[pre] -= 1
    for i in range(1, len(s)):
        # 当前位置的字母
        cur = s[i]
        # 后续该字母还有count[cur] -= 1个
        count[cur] -= 1
        if cur == pre:
            # 如果当前位置和上一个位置字母相同，就产生连续
            repeat += 1
        else:
            # 当前字母与上一个字母不连续，就打断联系
            ans.append([pre, repeat if repeat>1 else count[pre]])
            pre = cur # 更新
            # 更新pre连续次数为1
            repeat = 1
    # 母和紧随的数字作为一组进行排序，数字大的在前，数字相同的，则按字母进行排序，字母小的在前。
    ans.sort(key= lambda x:(-x[1], x[0]))
    return "".join(map(lambda x:x[0]+str(x[1]), ans))
print(result())