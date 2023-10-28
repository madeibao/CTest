
n = int(input())
lines = [input() for i in range(n)]
print(n)
print(lines)


def result(s):
    n = len(s)
    # 初始化a的数组
    dp = [0] * n
    if n >0:
        dp[0]=1
    if n>1:
        dp[1]=2
    if n>2:
        dp[2]=4
    if n>3:
        for i in range(3, n):
            dp[i] = dp[i-1]+dp[i-2]+dp[i-3]
    cArr = list(s)
    # 为每个字符串增加偏移量。
    for i in range(n):
        cArr[i] = (dp[i] + (ord(cArr[i])-97)) % 26 + 97
    return "".join(map(chr, cArr))
# 算法调用
for i in range(n):
    print(result(lines[i]))



