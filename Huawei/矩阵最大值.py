

n = int(input())
'''
5
1,0,0,0,1
0,0,0,1,1
0,1,0,1,0
1,0,0,1,1
1,0,1,0,1
'''
arr = [input().split(",") for i in range(n)] # 这里不用转化为int
print(n)
print(arr)


# 暴力破解
def result():
    ans = 0
    for i in range(n):
        maxV = int("".join(arr[i]), 2) # 初始值
        for j in range(1, n):
            arr[i].insert(0, arr[i].pop()) # 把后面的弹出来，然后插到头部。
            maxV = max(maxV, int("".join(arr[i]), 2)) # 搞完之后就比较大小。
        ans += maxV
    return ans
print(result())    