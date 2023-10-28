
s = input()
# I am a developer.
startIndex = int(input())
endIndex = int(input())
print(s)
print(startIndex, endIndex)


def result(s, start, end):
    sArr = s.split()
    # 先确定start的位置。0和start取最大，然后再跟len(sArr)-1取最小。
    start = min(max(0, start), len(sArr)-1)
    end = min(max(0, end), len(sArr)-1)
    if start > end:
        return s
    l = start
    r = end
    # 双指针，挪动
    while l<r:
        sArr[l], sArr[r] = sArr[r], sArr[l]
        l+=1
        r-=1
    return " ".join(sArr)


print(result(s, startIndex, endIndex))