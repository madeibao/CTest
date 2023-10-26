


def result():
    flag = True
    for i in range(len(arr)-1):
        if arr[i] !=arr[i+1] and (arr[i]>arr[i+1]) != flag:
            tmp = arr[i]
            arr[i] = arr[i+1]
            arr[i+1] = tmp
        flag = not flag
    return " ".join(map(str, arr))

try:
    arr = list(map(int, input().split()))
    print(result())
except ValueError:
    print("[]")



# 4 1 5 3 2 