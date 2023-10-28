

arr = input().split()
sumV = 0
for i in range(len(arr)):
    sumV += len(arr[i])
print(round(sumV / len(arr), 2)) # 重要的是保留两位小数。我去