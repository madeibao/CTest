

s = input()
print(s)


def result():
    cnt = {}
    for c in s:
        cnt[c] = cnt.get(c, 0)+1
    ans = []
    mid = "" # 记录成单出现的
    for k in cnt.keys():
        # 计数>=2成对出现。
        if cnt[k] >=2:
            n = cnt[k] // 2 # 相除得到一半
            ans.extend([k] * n)
        # 字母数量只有1个，或者大于2，但是为计数。最后肯定只会剩余一个单词可用
        if cnt[k]%2 !=0 and (mid == "" or k < mid):
            mid = k
    # 排序一波
    ans.sort()
    left="".join(ans)
    ans.reverse()
    right ="".join(ans)
    return left+ mid + right

print(result())