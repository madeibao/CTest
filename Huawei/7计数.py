
arr = list(map(int, input().split()))
print(arr)


def result():
    totalGo = sum(arr)
    # n表示一共几个
    n = len(arr)
    # p[i]表示每个人喊了几次过
    p = [0] *n
    i = 1
    j = 0
    while totalGo > 0:
        # 要么整出7，要么把i转化为字符串，然后找7能找到(find方法找到了就不等于-1)
        if i%7==0 or str(i).find("7")!=-1:
            totalGo -= 1 # 找到一个total就要减去1
            p[j] += 1 # p[i]表示每个人喊了几次过
        i += 1 # i自增1
        j += 1 # j也要自增1
        if j>=n: # j越界了，就回到0上。
            j = 0
        # idx 是一个7的倍数，或者含7的数字，
        # idx % n 表示第几个人喊的过，映射为索引，就是idx % n - 1
    return " ".join(map(str, p)) 
print(result())


0 1 0
[0, 1, 0]
1 0 0