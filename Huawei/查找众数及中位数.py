


nums = list(map(int, input().split()))
# 10 11 21 19 21 17 21 16 21 18 15
print(nums)


def result():
    count = {}
    for num in nums:
        count[num] = count.get(num, 0)+1
    maxCount = max(count.values())
    # 将众数挑选出来
    mode = []
    for k in count:
        if count[k]==maxCount:
            mode.append(int(k))
    # 众数升序
    mode.sort()
    # 中位数取值
    mid = len(mode)//2
    if len(mode)%2==0:
        return (mode[mid] + mode[mid-1]) // 2
    else:
        return mode[mid]
print(result())