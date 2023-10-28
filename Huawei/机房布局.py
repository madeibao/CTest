def result():
    n = len(s)
    ans = 0
    i = 0 
    while i < n:
        if s[i] == "M":
            # 如果当前为机柜
            # 优先将电箱放到机柜的右边，如果机柜右边有间隔I的话，还要别越界
            if i+1<n and s[i+1] == "I":
                ans += 1
                # 如果放成功了的话，第i个位置为机柜，i+1的位置为电箱
                # 那么第i+2无论是机柜，还是空位，还是电箱都可以。所以这里i+2
                i += 2 # 注意要理解这个。
            # 上面右边搞不定，我们只能搞左边了。
            elif i-1>0 and s[i-1] == "I":
                # 如果左边没越界，并且左边有空位
                ans += 1
            # 两边都搞不定，只能返回无法放入电箱了
            else:
                ans = -1
                break
        i += 1 #往后走一个了。
    return ans
s = input()
print(s)
print(result())