
n = int(input())
dayCount = list(map(int, input().split()))
print(n)
print(dayCount)


dayIds = []
for i in range(30):
    dayIds.append(list(map(int, input().split())))
def result():
    employees = {}
    for i in range(len(dayIds)):
        ids = dayIds[i]
        for id in ids:
            if employees.get(id) is not None:
                employees[id]["count"] += 1
            else:
                employees[id] = {
                    "count":1, # 打卡次数
                    "firstDay":i # 统计出第一天的
                }
    arr=[]
    for id in employees.keys():
        arr.append((id, employees[id]["count"], employees[id]["firstDay"]))
    arr.sort(key= lambda x:(-x[1], x[2], x[0]))
    return " ".join(list(map(lambda x: str(x[0]), arr[:5])))


print(result())
