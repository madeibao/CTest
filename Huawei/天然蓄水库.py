

arr = list(map(int, input().split()))
print(arr)


def getResult(s):
    l = 0
    r = len(s)-1
    maxSum = 0
    while l<r:
        sum = 0
        lower = min(s[l], s[r])
        # 开始算面积
        for i in range(l,r+1):
            sum += max(0, lower-s[i]) # 小沟沟的水要，但是超过lower的为负数就不加呗。
        # 更新maxSum的值
        if sum > maxSum:
            maxSum = sum
            ans = [l,r, sum]
        # 下面就看怎么挪动指针了。
        if s[l]<s[r]: #左边低，右边高
            l += 1
        elif s[l]>s[r]: # 左边高，右边低
            r -= 1
        elif s[l+1]>=s[l]: # 这里左右相等啦。就要看后面的是否比当前的要高
            l += 1
        else:
            r -= 1
    # 为0
    if ans == 0 :print(0)
    else:
        print("{} {}:{}".format(ans[0], ans[1], ans[2]))
getResult(arr)