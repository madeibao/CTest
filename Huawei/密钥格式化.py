



k = int(input())
s = input()
# k = 4
# s = "5f3z-2e-9-w"
def result(s, k):
    sArr = s.split("-")
    first = sArr[0]
    if len(sArr) == 1:
        return first
    tmp = list("".join(sArr[1:]).upper()) # 转化为大写
    for i in range(len(tmp)):
        if i%k == 0:
            tmp[i] = "-" + tmp[i]
    return first+ "".join(tmp)


print(result(s, k))