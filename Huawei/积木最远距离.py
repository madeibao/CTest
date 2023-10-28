

# 5
# 1
# 2
# 3
# 1
# 4
# 5
# [1, 2, 3, 1, 4]
# 3



n = int(input())
arr = [int(input()) for i in range(n)]
print(n)
print(arr)


# 算法入口
def result(arr, n):
    idx = {}
    # 把字母搞成字典，然后进行对比嘛
    for i in range(n):
        num = arr[i]
        if idx.get(num) is None:
            idx[num] = [i]
        else:
            idx[num].append(i) # nums相同的里边绝对是升序排好的。
    ans = -1 # 初始化为-1是有原因的。因为如果没有更新，就返回-1啦。
    for k in idx.keys():
        if len(idx[k])>1: # 没有大于1没意义啊 .
            ans = max(ans, idx[k][-1] - idx[k][0]) # 
    return ans

print(result(arr, n))