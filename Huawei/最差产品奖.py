

n = int(input())
arr = list(map(int, input().split(",")))
print(n)
print(arr)


def result(arr, n):
    # 先把最小值初始化
    minV = min(arr[:n]) # 注意取数的时候是左闭右开，从0开始。
    ans = [minV] # 先初始化ans
    j = n
    while j < len(arr):
        if arr[j-n] > minV:
            minV = min(minV, arr[j])
        else:
            if arr[j] <= minV:
                minV = arr[j]
            else:
                minV = min(arr[j-n+1:j+1])
        ans.append(minV)
        j += 1
    return ",".join(map(str, ans))


print(result(arr,n))
