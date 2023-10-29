

r, c, s, minV = map(int, input().split())
arr = [list(map(int, input().split())) for i in range(r)]
print(r, c, s, minV)
print(arr)


def result(r, c, s, minV, arr):
    '''
    r : 调研区域的长
    c: 调研区域的宽
    s:正方形电站的边长
    minV : 正方形电站的最低发电量
    arr:调研区域每单位面积的发电量矩阵
    return :返回调研区域有几个符合要求正方形电站
    '''
    preSum = [[0 for j in range(c+1)] for i in range(r+1)]
    for i in range(1, r+1):
        for j in range(1, c+1):
            # 这里为啥+ arr[i-1][j-1] 因为后面是preSum[i-1][j]
            preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + arr[i-1][j-1] # 
    ans = 0
    for i in range(s, r+1):
        for j in range(s, c+1):
            square = preSum[i][j] - (preSum[i-s][j]+preSum[i][j-s]) + preSum[i-s][i-s]
            if square>=minV:
                ans+=1
    return ans

print(result(r, c, s, minV, arr))