

n = int(input())
bin1 = input()
bin2 = input()
'''
4
1001
0001
'''
print(n)
print(bin1)
print(bin2)


def result():
    # 找出bin2值为0的位，并统计对应位上bin1的值为0的有x个
    x = 0
    # 找出bin2值为0的位，并统计对应位上bin1的值为1的有y个
    y = 0
    # 统计bin1总共有多少个1
    a = 0
    # 统计bin1总共有多少个0
    b = 0
    for i in range(n):
        if bin1[i] == "0":
            b += 1
            if bin2[i]=="0":
                x += 1
        else:
            # bin1[i] == "1"
            a += 1
            if bin2[i] == "0":
                y += 1
    return x*a+y*b-x*y

print(result())