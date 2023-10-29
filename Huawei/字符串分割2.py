


k = int(input())
s = input()
print(k)
print(s)


def convert(s):
    lower = 0
    upper = 0
    for c in s:
        if 'z'>= c >= 'a':
            lower += 1
        elif 'Z'>= c >= 'A':
            upper += 1
    if lower>upper:
        return s.lower() # 牛，不仅仅单个字符转，还可以一起转。
    elif lower<upper:
        return s.upper()
    else:
        return s

def result():
    arr = s.split("-")
    ans = []
    ans.append(arr[0]) # 第一个要不要转，试试，要转就转。
    newStr = "".join(arr[1:]) # 把他们链接起来，
    for i in range(0, len(newStr), k):
        # 步进是k，这个好
        subStr = newStr[i:i+k] # 因为左闭右开，所以i+k只能取到i+k-1
        ans.append(convert(subStr))
    return "-".join(ans)
print(result())