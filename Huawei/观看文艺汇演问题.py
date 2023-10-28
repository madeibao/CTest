
n = int(input())
matrix = [list(map(int, input().split())) for i in range(n)]
for x in matrix:
    x[1] += x[0] # 把结束时间算出来。
print(matrix)

# 算法入口
def result():
    # matrix表示开始时间，结束时间。
    matrix.sort(key=lambda x:(-x[1], -x[0]))
    s1 = matrix[0][0] # 最大的开始时间，
    ans = 1
    for s2, e2 in matrix:
        if s1-e2>15:
            ans+=1
            s1=s2 # 更新s1的值，用来比较下一个。
    return ans
print(result())



# 2
# 0 60
# 90 60
# [[0, 60], [90, 150]]      
# 2