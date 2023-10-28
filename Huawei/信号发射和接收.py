

m, n =map(int, input().split())
arr = list(map(int, input().split()))


def common(stack,anth,ret, i, j):
        while len(stack)>0 and anth[i][j] > stack[-1]:
            ret[i][j] += 1
            stack.pop()
        if len(stack) > 0:
            if anth[i][j] == stack[-1]:
                ret[i][j]+=1
                stack.pop()
            else:
                ret[i][j]+=1
        stack.append(anth[i][j])

def result2(m,n,arr):
    # 初始化矩阵
    anth = [[0 for j in range(n)] for i in range(m)]
    for i in range(m*n):
        r = int(i/n) # 获得行号
        c = int(i%n) # 获得列数
        anth[r][c] = arr[i]
    ret = [[0 for j in range(n)] for i in range(m)]
    for i in range(m):
        stack = []
        for j in range(n):
            common(stack,anth,ret, i, j)
    for j in range(n):
        stack = []
        for i in range(m):
            common(stack,anth,ret, i, j)
    print(ret)
    # res = " ".join([" ".join(map(str, i) for i in ret)])
    print(f'{m} {n} \n(res)')
# result2(m, n, arr)
    
# 算法调用
print(result2(m, n, arr))



# 1 6
# 2 4 1 5 3 3
