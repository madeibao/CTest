

arr = list(map(int, input().split(",")))
length = int(input())
# print(arr)
# print(length)



def dfs(arr, index, level, path, res):
    if len(path) >= level:
        res.append(",".join(map(str, path[:]))) # 直接一步到位，把逗号都处理好了
        # return # 如果这里return 掉，那么永远无法获取更长位数的。
        # 更长的是通过下面的遍历结束掉循环的。比如len(arr)-index-1<level了。
    for i in range(index, len(arr)):
        path.append(arr[i])
        dfs(arr, i+1, level, path, res)
        path.pop()

def result(length, arr):
    if length > len(arr):
        return "None"
    '''
    题目保证所有数字都是不重复的。
    '''
    arr.sort() # 先排序
    res = []
    dfs(arr, 0, length, [], res)
    if len(res)>0:
        for s in res:
            print(s)
    else:
        print("None")
result(length, arr)


