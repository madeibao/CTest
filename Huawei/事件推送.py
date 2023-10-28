

def bs(arr, target):
    l = 0
    r = len(arr) -1
    while l<=r:
        m = (l+r)//2
        if arr[m] > target:
            r = m-1
        elif arr[m]<target:
            l = m+1
        else:
            return m
    return -l-1


def result():
    for i in a:
        j = int(bs(b, i))
        if j>=0: # 说明在里找到对应的值
            print(f"{i} {b[j]}")
        else:
            # j小于0，在对应的数组肯定是没有找到值，这个时候-j-1是插入的位置。
            insertIdx = -j-1
            if insertIdx == len(b):
                # 这个标明a比b的最大值还要大。没法玩。
                continue
            if b[insertIdx] - i <= r: 
                # 如果insertIdx小于len(b)就保证Ai<= Bj
                # 1.Ai<= Bj
                # 2.Ai,Bj之间的距离小于等于R
                print(f"{i} {b[insertIdx]}") # 这里要转过弯来哦

# a = [1, 5, 5, 10]
# b = [1, 3, 8, 8, 20]
# result()

m, n, r = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
# 4 5 5
# 1 5 5 10
# 1 3 8 8 20
print(m, n, r)
print(a)
print(b)

result()

