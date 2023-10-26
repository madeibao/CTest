
  
# 4,4,0,0,3,3


def result(m,n,i,j,k,l):
    matrix= [[0] * n for i in range(m)]
    matrix[i][j] = 1
    matrix[k][l] = 1
    # count 用来记录未被扩容的数量
    count = m*n-2
    # 多源bfs的实现
    queue = [[i, j], [k, l]]
    # 上下偏移量
    directs=((-1,0),(1,0),(0,-1),(0,1))
    day = 1 # 记录下天数，
    # 如果没有扩散的点了，或者所有店已经被扩撒了，就停止循环
    while len(queue)>0 and count>0:
        x, y = queue.pop(0)
        # 我们假设初始扩散点的 1 代表第 1 秒被扩散到的，则下一波被扩散点的值就是1+1，即第 2 秒被扩散到的
        day = matrix[x][y]+1
        # 然后开始深搜
        for dirx, diry in directs:
            new_x = x+dirx
            new_y = y + diry
            # 判断边界条件，
            if 0<=new_x<m and 0<=new_y<n and matrix[new_x][new_y] == 0:
                # 将点被扩散的时间记录为该点的值
                matrix[new_x][new_y] = day
                # 被扩散到的点将变为新的扩散源
                queue.append(matrix[new_x][new_y])
                # 未被扩散点的数量--
                count -= 1
    return day-1


m,n,i,j,k,l=map(int, input().split(","))
result(m,n,i,j,k,l)