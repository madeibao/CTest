


n = int(input())
tree = [1 for _ in range(n + 1)]
m = int(input())
m_l = input().split()
k = int(input())
loc_0 = []
max_l = 0
for i in m_l:
    tree[int(i)] = 0
left = 1
right = 2
while right <= n:
    if tree[left] == 0:
        k = k - 1
        loc_0.append(left)
    if tree[right] == 0:
        k = k - 1
        loc_0.append(right)
    if k == 0:
        max_l = max(right - left + 1, max_l)
    elif k < 0:
        loc = -(k + 1)
        left = loc_0[loc] + 1
        k += 1
    right += 1
print(max_l)
