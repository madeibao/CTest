r = int(input())
N = list(map(int, input().split()))
d = int(input())
print(r, d)
print(N)

# # 输入获取
# r = int(input())
# N = list(map(int, input().split()))
# d = int(input())

# r,d= 5,30
# N = [10, 5, 0, 1, 3, 2]
 
# 算法入口
def result():
    D = list(map(int, str(bin(d))[2:]))
    D.reverse()
 
    count = 0
 
    if len(N) > len(D):
        for i in range(len(D), len(N)):
            count += N[i]
 
    while True:
        D2 = D[:] # 复制一份
        for i in range(len(D)-1, 0, -1):
            if N[i] > 0:
                diff = N[i] - D2[i] # 把当前位置的差异求出来
                if diff >= 0:
                    N[i] = diff # 更新N[i] 相当于用掉了当前个数然后剩余的。
                    D2[i] = 0 #当前位要置零
                else:
                    D2[i] = 0 # 就要向其他位借了。
                    D2[i-1] += abs(diff) * 2 # 降低一位，那不就相当于乘以2.
                    N[i] = 0 # N[i]这已经把他减去了。（因为 abs(diff)）所以就位0啦
            else: # N[i]=0
                D2[i-1] += D2[i] * 2 # 只能降位来匹配
                D2[i] = 0# 降位之后原来的位置就要置0 D2是D的复制哈。别理解错了。
 
        flag = False # 做个标记，判断是否正确
        if N[0] >= D2[0]: # 最终第0位承担了所有。
            N[0] -= D2[0]
            count += 1
            # print(count)
        else:
            N[0] -= D2[0]
            D2[0] = 0 # 因为N[0] -= D2[0]的逻辑，
            for i in range(len(D)):
                if N[i] < 0: # 小于0的要准备升位
                    if i != len(D) - 1:
                        N[i+1] += N[i] >> 1
                        N[i] = 0
                    else:
                        flag = True
                else:
                    count += 1
                    break
        if flag:
            break
    return count
# 算法调用
print(result())