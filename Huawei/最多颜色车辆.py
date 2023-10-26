

def result(arr, n):
    # 先把计数初始化啦
    count = {str(i): 0for i in range(3)}
    # print(count)
    l = 0 # 窗口左边界。
    r = l + n # 窗口右边界。
    # 先初始化，搞满滑动窗口
    for c in arr[l:r]: # 注意r是取不到的。比如l = 0，n=2，r = 2,实际取0,1
        count[c]+=1
    # 统计出来初始化滑动窗口的值。
    maxV = max(count.values())
    # 开始移动了
    while r<len(arr):
        # 加进来一个。
        add = arr[r]
        # 去掉最左边的
        remove = arr[l]
        # 计数对应的增减。
        count[add]+=1
        count[remove]-=1
        # 移动指针
        l+=1
        r+=1
        # 更新一波最大值,只要跟记录的最大值与加进来字符的总次数进行比较，去掉的那个都去掉了，还关心他干啥，肯定是小了啦
        maxV = max(maxV,count[add])
    return maxV


arr = input().split()
n = int(input())
print(arr)
print(n)


result(arr, n)