
total = int(input())
arr = list(map(int, input().split()))
n = int(input())
print(total)
print(arr)
print(n)


def result():
    arr.sort()
    ans = 0
    for i in range(total):
        for j in range(total-1, i, -1): # 注意j的取值啦，倒着取，取到i+1
            sumV = arr[i] + arr[j] # 把指针的求和算出来。
            if sumV == n:
                ans+=1
            elif sumV <n:
                break
    return ans

print(result())



5
1 2 2 2 3
4