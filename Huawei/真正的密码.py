

def result(arr):
    setArr = set(arr)
    # 先按照长度排序，然后按照字典序排序
    arr.sort(key=lambda s: (len(s), [ord(c) for c in s]))
    # 倒序遍历嘛。现在已经按照长度升序排列。那么倒数第一个肯定是最长的，字典序最大的。
    for i in range(len(arr)-1, -1, -1):
        s = arr[i] # 取一个。
        flag = True # 先默认他可以。然后碰到返例就否定。
        # 截取当前字符串的字串。
        for j in range(len(s)-1, 0, -1):
            # s[:j]是取不到j的，也就是取不到len(s)-1，也就是从len(s)-2开始。len(s)-1不用判断啊。
            if s[:j] not in setArr:
                flag = False
                break
        # 遍历了一圈了
        if flag:
            return s
    return ""
# arr = ['a', 'b', 'c', 'd', 'f']
# arr = ['h', 'he', 'hel', 'hell', 'hello', 'o', 'ok', 'n', 'ni', 'nin', 'ninj', 'ninja']
arr = input().split()
print(arr)
print(result(arr))