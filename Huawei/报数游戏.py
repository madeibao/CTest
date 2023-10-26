

def result():
    # 初始化arr
    if m<1 or m>=100:
        print("ERROR")

    arr = [i+1 for i in range(100)]
    num = 0
    while len(arr)>=m:
        num += 1
        count = arr.pop(0)
        if num == m:
            num = 0
        else:
            arr.append(count)
    arr.sort()
    print(",".join(map(str, arr)))

    
# m = 3
m = int(input())
result()