


def isExist(nums, m):
    remain = set()
    remain.add(0)
    total = 0
    for num in nums:
        total += num
        if total %m in remain:
            return 1
        else:
            remain.add(total % m)
    # 最后别忘了。
    return 0

def result(cases):
    for case in cases:
        print(isExist(case[0], case[1]))


# 输入获取
cases = []
while True:
    line = input()
    if line =="":
        result(cases)
        break
    else:
        n, m = map(int, line.split())
        nums = list(map(int, input().split()))
        cases.append([nums,m])




# 6 7
# 2 1 2 6 3 5 5
# 10 11
# 1 1 1 1 1 1 1 1 1 1