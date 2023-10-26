


# 算法
import math
def result(arr):
    # 题目说会输入 n*n 个值
    n = int(math.sqrt(len(arr)))
    # 将一维 arr 输入转为二维矩阵 matrix
    matrix = [[0] * n for i in range(n)]
    # 将矩阵中所有感染区域位置记录到 queue 中,这里选择 queue 先进先出的原因是 保证当天的感染区域并发扩散
    queue = [] # 统计毒源
    for i in range(n):
        for j in range(n):
            # 这里把matrix和arr映射。
            matrix[i][j] = arr[i*n+j]
            if matrix[i][j] == 1:
                queue.append([i, j])
    # 全是感染区，或者全是健康区
    if len(queue) == 0 or len(queue) == len(arr):
        return -1
    health = len(arr)-len(queue)
    directs = ((-1, 0),(1, 0),(0, -1),(0, 1))

    day = 0
    # 判断循环条件，如果健康区为0，说明感染完毕了
    while health>0 and len(queue)>0:
        newque = [] # 新建立一个queue出来。
        for x, y in queue:
            # 这里也是优秀哦。直接在matrix[x][y]上加。所以后面day要减1
            day = matrix[x][y]+1
            for dirx, diry in directs:
                new_x = x+dirx
                new_y = y+diry
                # 判断边界条件
                if 0<=new_x<n and 0<=new_y<n and matrix[new_x][new_y] == 0:
                    health-=1
                    matrix[new_x][new_y] = day
                    newque.append([new_x,new_y])
        print(newque)
        queue = newque # 还有这个
    return day-1

arr = list(map(int, input().split(",")))
print(result(arr))


# 1,0,1,0,0,0,1,0,1