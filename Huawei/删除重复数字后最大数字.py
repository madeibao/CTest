


def result():
    cnt = [0] *10 # 数字都是0-9呀，所以。
    s = []
    vis = [0] * 10
    # 统计字符出现的次数
    for c in n:
        cnt[int(c)] += 1
        s.append(int(c)) # 转化为int型再添加进去。
    st = [] # 定义栈
    for i in range(len(s)):
        cnt[s[i]] -= 1 #要对这个字符进行处理，所以先要减去1
        if not st:
            # 栈为空，那就要把他加进来
            st.append(s[i])
            vis[s[i]] = 1 # 这个数标记为已经访问了。
        else:
            # 栈不为空，就要进行单调栈处理逻辑
            # 栈不为空，当前值大于栈顶元素，
            # cnt[st[-1]]>0 不然你把它弹出，后面没有了就尴尬了
            # vis[s[i]] 要为0,不能访问过。如果访问过一定在里边，或者后面还有。
            while st and st[-1]<s[i] and cnt[st[-1]] and not vis[s[i]]:
                vis[st[-1]] = 0 # 弹出之后，要把这个标记为未访问。这个重要。
                st.pop()
            # 弹栈完了,vis[s[i]]不能访问过。
            if not vis[s[i]]:
                st.append(s[i]) # 加入单调栈里。
                vis[s[i]] = 1 # 标记为已访问。
    # 栈里的元素保留的就是最棒的。
    print(st)
    ans = 0
    return int("".join(map(str, st)))
result()



n = input()
# 12341
print(n)