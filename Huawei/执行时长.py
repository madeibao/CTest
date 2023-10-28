maxCount = int(input())
n = int(input())
tasks = list(map(int, input().split()))



def getResult():
    time = 0
    remain = 0
 
    for task in tasks:
        if task + remain > maxCount:
            # 等待数
            remain = task + remain - maxCount
        else:
            remain = 0
        # 时间都加1
        time += 1
    # 任务执行完了，还有剩余，
    while remain > 0:
        remain -= maxCount
        time += 1
 
    return time
 
 
# 算法调用
print(getResult())