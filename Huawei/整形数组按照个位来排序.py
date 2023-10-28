


arr = input().split(",")
print(arr)

def result():
    arr.sort(key=lambda x: x[-1])
    return ",".join(arr)


print(result())
