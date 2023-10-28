

arr = list(map(int, input().split(",")))
# 1,0,0,0,1
print(arr)


cnt = 0
# 前面补0
arr.insert(0, 0)
# 后面补0
arr.append(0)
for i in range(1, len(arr)-1):
    if arr[i] == 0 and arr[i-1] == 0 and arr[i+1] == 0:
        cnt += 1
        arr[i] = 1
print(cnt)