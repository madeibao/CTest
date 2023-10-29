

m, n = map(int, input().split())
matrix = [list(map(int,input().split())) for i in range(m)]
print(m, n)
'''
5 3
-1 0 1
0 0 0
-1 0 0
0 -1 0
0 0 0
'''
print(matrix)


# 输入获取
# m, n = map(int, input().split())
# matrix = [list(map(int, input().split())) for _ in range(m)]
 
 
# 算法入口
def getResult():
    # 临时记录每行的连续0个数
    rowConstantZeroCount = [0] * m
    # 临时记录每列的连续0个数
    colConstantZeroCount = [0] * n
 
    # 记录每行的最大连续0个数
    rowConstantZeroMaxCount = [0] * m
    # 记录每列的最大连续0个数
    colConstantZeroMaxCount = [0] * n
 
    for i in range(m):
        for j in range(n):
            if matrix[i][j] == 0:
                # 如果第i行，第j列为0, 则第i行连续0个数+1，第j列连续0个数+1
                rowConstantZeroCount[i] += 1
                rowConstantZeroMaxCount[i] = max(rowConstantZeroMaxCount[i], rowConstantZeroCount[i])
 
                colConstantZeroCount[j] += 1
                colConstantZeroMaxCount[j] = max(colConstantZeroMaxCount[j], colConstantZeroCount[j])
            else:
                # 如果如果第i行，第j列不为0,则第i行连续0中断，第j列连续0中断
                rowConstantZeroCount[i] = 0
                colConstantZeroCount[j] = 0
 
    print(len(list(filter(lambda val: val >= n // 2, rowConstantZeroMaxCount))))
    print(len(list(filter(lambda val: val >= m // 2, colConstantZeroMaxCount))))
 
 
getResult()

