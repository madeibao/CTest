


s = list(input())
length = len(s)
k = int(input())  # 第k个多的
alpha = {}
left = 0
for i in range(length):
    if s[i] not in alpha.keys():  # 先判断该字母是否存在于字典中
        alpha[s[i]] = 0
    if s[i] != s[left]:  # 再判断值是否相等
        alpha[s[left]] = max(alpha[s[left]],i-left)
        left = i
    elif i == length - 1:  # 最后一个字母和上一个字母相同，需要另外处理
        alpha[s[left]] = max(alpha[s[left]],i-left+1)
res = []
for i in alpha:
    res.append(alpha[i])
res.sort(reverse=True)
print(res[k - 1] if k < length else -1)
