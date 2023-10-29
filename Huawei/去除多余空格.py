


s = input()
arr = list(map(lambda x:list(map(int, x.split())) , input().split(",")))
print(s)
print(arr)


import copy
def result(arr, s):
    """
    arr:关键词的开始和结束坐标，关键词间以逗号区分，关键词内的开始和结束位置以单空格区分
    s:原始字符串
    """
    qStart = False # 用来标记是否有'的符号。从false->true，就是'开头，然后从true->false就是就是'结尾。常用操作
    needDel = [] # 需要删除的编号。
    for i in range(len(s)):
        # 如果s[i]为空格，s[i-1]为空格，还有就是不能再'里边，就标记为删除
        if s[i] == " " and s[i-1] == " " and not qStart:
            needDel.append(i)
        if s[i] == "\'":
            qStart = not qStart
    sArr = list(s) # 转化为列表，便于取数
    # 深拷贝来一波
    ans = copy.deepcopy(arr)
    for d in needDel:
        sArr[d] = "" # 删除空格嘛。
        for i in range(len(arr)):
            start = arr[i][0] # 记录关键词的第一个。
            if d<start:
                ans[i][0] -= 1
                ans[i][1] -= 1 # 前面空格删除了，对应的数据也要往前挪动。
    print("".join(sArr))
    print("".join(list(map(lambda x: str(x), ans))))
result(arr, s)



# Life is painting a  picture, not doing 'a  sum'
# 8 15,20 26,43 45