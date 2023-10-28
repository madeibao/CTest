


def loop(arr, i, count):
    # 走到哪里了。i是上一步的位置，再加上上一步位置的值arr[i]
    j = i+arr[i]
    # 三种情况。刚好到了尾部了，就返回
    if j == len(arr)-1:
        return count
    # 没到尾部，count+1后继续循环。
    elif j<len(arr)-1:
        count += 1
        return loop(arr,j, count)
    else: # 越界了，题目说了不能往回走哈。
        return -1
def result():
    res = []
    # 第一步自选，走好第一步，只能到len // 2
    for i in range(1, len(arr)//2):
        # 走好第一步。
        res.append(loop(arr, i, 2))
    tmp = list(filter(lambda x: x>0, res))
    tmp.sort() # 排序嘛。
    if len(tmp)>0: # 步数越小越好。
        return tmp[0]
    else:
        return -1

arr = list(map(int, input().split()))
# 7 5 9 4 2 6 8 3 5 4 3 9
print(arr)


print(result())