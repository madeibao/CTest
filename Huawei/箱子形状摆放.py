

# 读入
s, n = list(map(str,input().split()))
n = int(n)
# a:开n个list
a = [[] for i in range(n)]
ok = False 
m = len(s)
j = 0
# 枚举s，模拟摆放到a里去
for i in range(m):
    a[j].append(s[i])
    # 模拟移动
    if ok:
        j -= 1
        if j == -1: # 如果移动出边界了则换方向
            j += 1
            ok = not ok 
    else:
        j += 1
        if j == n: # 如果移动出边界了则换方向
            j -= 1
            ok = not ok
# 按题目要求输出
res = []
for i in range(n):
    res.append("".join(map(str , a[i])))
print("\n".join(res))

