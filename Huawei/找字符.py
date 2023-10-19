


char1 = input()
char2 = input()
s1 = {i for i in char1} # 去重
s2 = {i for i in char2}
s1 = sorted(s1) # 排序
s2 = sorted(s2)
result = ''
for i in s1:
    if i in s2:
        result += i
print(result)