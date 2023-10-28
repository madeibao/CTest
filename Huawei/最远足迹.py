
s = input()
# ferg(3,10)a12fdsf3(3,4)f2r3fasf(5,10)
print(s)


def result():
    maxFar = 0
    ans = "(0,0)" # 不合法的时候返回"(0,0)"
    l = 0
    for i in range(len(s)):
        if s[i] == "(":
            l=i+1
        elif s[i] == ")":
            x, y = s[l:i].split(",")
            if x[0] == '0' or y[0] == '0':
                continue # 舍弃,因为还有前导0
            # 不含前导0
            x = int(x)
            y = int(y)
            #判断是否越界
            if x <= 0 or x >= 1000 or y <= 0 or y >= 1000:
                continue # 越界了不行。
            # 没越界
            far = x ** 2 + y ** 2
            if far > maxFar:
                # 更新maxFar，只有大于了才更新。如果等于也不更新满足题目的最先面出现的那个。
                maxFar = far
                ans = f"({x},{y})"
    return ans

s = 'fagag(05,14)faf(10,9)ff646(8,1)'

print(result())
