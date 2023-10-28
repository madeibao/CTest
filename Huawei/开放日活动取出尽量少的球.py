sumV, n = map(int, input().split())
arr = list(map(int, input().split()))

def result(sumV, arr, n):
    total = sum(arr)
    if total <= sumV:
        return "[]"
    max_maxCapacity = max(arr)
    min_maxCapacity = int(sumV / n)
    # ans 保存题解，初始题解为 min_maxCapacity 对应的题解
    ans = list(map(lambda count: count-min_maxCapacity if count>min_maxCapacity else 0, arr))
    while max_maxCapacity - min_maxCapacity > 1:
        maxCapacity = int((max_maxCapacity+ min_maxCapacity)/2 )
        # tmp 数组保存的是每个桶移除的球的数量
        tmp = list(map(lambda count:count - maxCapacity if count>maxCapacity else 0, arr))
        remain = total - sum(tmp)
        if remain > sumV:
            max_maxCapacity = maxCapacity
        elif remain<sumV:
            min_maxCapacity = maxCapacity
            ans = tmp
        else:
            ans = tmp
            break
    return ans
print(result(sumV, arr, n))