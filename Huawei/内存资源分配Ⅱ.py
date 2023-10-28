

# lines = list(input().split("，"))
# tmp = []
# for line in lines:
#     key, cnt = map(int, line.split(":"))
#     if cnt == 0:continue
#     tmp.append([key, cnt])
# tmp.sort(key = lambda x: x[0])
# shenqing = list(map(int, input().split("，")))



cashs = [[1, 128], [32, 4], [64, 2], [128, 1]]
sq = [50, 36, 64, 128, 127]

ans = []
for i in sq:
    if i < cashs[0][0] or i > cashs[-1][0]:
        ans.append("false")
        continue
    l = 0
    r = len(cashs)-1
    while l < r:
        mid = (l+r)//2
        if cashs[mid][0] > i:
            r = mid
        else:
            l = mid + 1
    # print("l:", l, "r:", r)
    # 循环完之后得到cashs[l]
    if cashs[l][1]>0:
        cashs[l][1] -= 1
        ans.append("true")
    # 这里不能用elif是另一个逻辑了。只要他的值为0就要删除。为了保证下一个循环有值啊。
    if cashs[l][1] == 0:
        del cashs[l]
    # print(ans)
    # print(cashs)
print(ans)