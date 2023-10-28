n = int(input())
arr = list(map(int, input().split()))
print(n)
print(arr)


def result():
    arr.sort()
    if arr[0] == 1: # 后面的所有的都可整除1，所以都图上一种颜色。
        return 1
    color = [False] * n
    count = 0
    for i in range(n):
        if color[i]: # 如果已经上色了，就跳过
            continue
        # 没上色
        color[i] = True # 没上色就让他上色，然后把后面的整出他的全部上色
        for j in range(i+1, n):
            if not color[j] and arr[j] % arr[i] == 0:
                color[j] = True
        count += 1 # 全部上完色之后，才能加1哈
    return count
print(result())