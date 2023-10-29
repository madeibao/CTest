


s, n = map(int, input().split())
print(s, n)



def result():
    left, right = -1, -1
    if n % 2==0:
        halfLen = n//2-1
        left = s // n - halfLen
        right = s // n + 1 +halfLen
    else :
        mid = s // n
        halfLen = n // 2
        left = mid - halfLen
        right = mid + halfLen
    if left<=0:
        return -1
    return " ".join([str(i) for i in range(left, right+1)])


print(result())

