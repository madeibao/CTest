

def result(arr):
    # 先排序一遍
    arr.sort(key = lambda s: (len(s), [ord(c) for c in s]))
    setA = set(arr)
    ans = ""
    while len(arr)>0:
        s = arr.pop()
        end = len(s)-1
        if end == 0 and ans == "":
            ans = s
            continue
        while s[:end] in setA:
            if end == 1:
                return s
            else:
                end -= 1
    return ans   


arr = input().split()
print(arr)

print(result(arr))