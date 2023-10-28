

def result():
    times.sort() # 升序排列
    # 初始化每条线的时间
    arr = [0] * m
    for i in range(len(times)):
        arr[i%m] += times[i] # 取余，常规做法。
    # print(arr)
    return max(arr)


m, n = map(int, input().split())
times = list(map(int, input().split()))
print(m, n)
print(times)

print(result())