

hour, minute = input().split(":") #
print(hour, minute) # 不能转int啊转int就可能没有0了。
print(type(hour), type(minute))


import re
reg = re.compile(r"(([01][0-9])|([2][0-3]))[0-5][0-9]")
def dfs(arr, path, res):
    # 先写终止条件
    if len(path) == 4:
        timeStr = "".join(path[:]) # 这里输入进来的就是字符，而不是数字。
        # print(timeStr)
        # 判断时间是否符合要求
        if reg.search(timeStr) is not None:
            res.append(timeStr)
        return
    for i in range(len(arr)):
        path.append(arr[i])
        dfs(arr, path, res)
        # 回溯
        path.pop()

def result():
    arr = list(hour)
    arr.extend(list(minute))
    arr = list(set(arr)) # 去重，得到唯一。
    res = []
    dfs(arr, [], res) # 求得所有的结果了。
    # print(res)
    index = res.index(hour + minute) # 这个也是非常好，通过值来找index
    # print(index,type(index))
    if index == len(res)-1:
        # 到了最后一个了,比如23:59
        reTime = res[0]
    else:
        reTime = res[index+1]
    ans = list(reTime) # 转化为列表
    ans[1] += ":" # 按照格式输出
    return "".join(ans)


print(result())

