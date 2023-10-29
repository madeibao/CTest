
n, k = map(int, input().split())
arr = list(map(int, input().split()))
print(n, k)
print(arr)

def result(n,k,arr):
    ans = 0
    for i in range(n):
        count = {}
        for j in range(i, n):
            c = arr[j]
            if count.get(c) is None:
                count[c] = 1
            else:
                count[c] += 1
            if count[c]>=k:
                ans += n-j
                break
    return ans
result(n,k,arr)