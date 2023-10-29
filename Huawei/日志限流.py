

# 数据输入
n = int(input())
records = list(map(int, input().split()))
total = int(input())
# print("total:", total)
# print(records)
# print(sum(records))

def getResult(n, records, total):
    if sum(records)<=total:
        return -1
    # 开始初始化limit
    left = int(total/n)
    records.sort() # 先排序。
    # right = records[-1] # 取最大值。
    right = max(records) # 取最大值。
    mid = left
    while right - left > 1: # 这个条件要拿捏死死的。
        mid = int((left+right)/2)
        tmp = 0
        # print(mid)
        for record in records:
            tmp += min(record, mid)
        if tmp > total:# mid取小了。
            right = mid
        elif tmp<total:# mid取大了。
            left = mid
        else:
            return mid
    return mid
# n = 6
# records = [3,3,8,7,10,15]
# total = 40
res = getResult(n, records, total)
print(res)