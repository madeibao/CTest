

n = int(input())
s = list(map(int, input().split()))
length = int(input())
left = 0
right = length
res = []
while right <= n:
    res.append(sum(s[left:right]))
    left += 1
    right += 1
print(max(res))
